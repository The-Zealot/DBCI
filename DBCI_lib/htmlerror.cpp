#include "htmlerror.h"

HtmlError* HtmlError::_htmlError = nullptr;

HtmlError::HtmlError()
{
    _currentErrorCode = 0;
    init();
}

void HtmlError::setCurrentErrorCode(int newCurrentErrorCode)
{
    _currentErrorCode = newCurrentErrorCode;
}

HtmlError *HtmlError::getError()
{
    if (_htmlError == nullptr)
        _htmlError = new HtmlError();

    return _htmlError;
}

const QString HtmlError::toString() const
{
    if (_currentErrorCode >= _errors.size() or _currentErrorCode < 0)
    {
        return "Unknown error";
    }

    return _errors[_currentErrorCode];
}

void HtmlError::init()
{
    _errors.push_back("No error");
    _errors.push_back("Empty data");
}
