#include "htmlparser.h"

HtmlParser::HtmlParser(QObject *parent)
{
    _manager = new QNetworkAccessManager();
    connect(_manager, &QNetworkAccessManager::finished, this, &HtmlParser::replyFinished);
    connect(this, &HtmlParser::pageLoaded, this, &HtmlParser::getArmoryUrl);

    _isFirstLoad = true;
}

HtmlParser::~HtmlParser()
{
    if (_manager != nullptr)
    {
        delete _manager;
    }
}

QByteArray HtmlParser::loadPage(QUrl url)
{
    QNetworkRequest request(url);
    _manager->get(request);
}

QString HtmlParser::getTagValue(QString page, QString tag, QString closeTag)
{
    QString html = page;
    int pos1 = html.indexOf(tag) + tag.size();
    if (pos1 - tag.size() < 0)
        return "";

    int pos2 = html.indexOf(closeTag, pos1);

    return html.mid(pos1, pos2 - pos1);
}

QStringList HtmlParser::getCharacterData(const QString &name, QString realm)
{
    QString url = QString("https://cp.pandawow.me/armory.html?name=%1&realm=%2").arg(name).arg(realm);

    _armoryData.clear();
    _armoryData.setRealm(realm.toInt());

    _isFirstLoad = true;
    loadPage(url);
}

ArmoryData HtmlParser::getArmory()
{
    return _armoryData;
}

void HtmlParser::replyFinished(QNetworkReply* reply)
{
    qDebug() << "Reading url:" << reply->url().toString();
    _data = reply->readAll();

    if (_isFirstLoad)
    {
        emit pageLoaded();
    }
    else
    {
        parse();
        emit parsed();
    }

    reply->deleteLater();
}

void HtmlParser::getArmoryUrl()
{
    _isFirstLoad = false;

    QString armoryUrl = getTagValue(_data, "<tr class=\"odd\">\n<td><a href=\"", "\">");
    QStringList characterData = getTagValue(_data, "<tr class=\"odd\">\n", "</tr>").split("</td>");

    _armoryData.setName(getTagValue(characterData.at(0), ".html\">", "</a>"));
    _armoryData.setFaction(getTagValue(characterData.at(2), "<td>"));
    _armoryData.setRace(getTagValue(characterData.at(3), "<td>"));
    _armoryData.setClass(getTagValue(characterData.at(4), "<td>"));
    _armoryData.setId(getTagValue(armoryUrl, QString("char-%1-").arg(_armoryData.realm()), ".html").toInt());

    loadPage(armoryUrl);
}

void HtmlParser::parse()
{
    qDebug() << "Parsing...";

    QString guildTag = getTagValue(_data, "https://cp.pandawow.me/guild/show", "</a>");
    if (guildTag != "")
    {
        _armoryData.setGuild(getTagValue(guildTag, ">"));
    }

    qDebug() << "Parsing has done";
}
