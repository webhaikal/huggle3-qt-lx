//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "generic.hpp"
#include <QMessageBox>
#include <QUrl>
#include <QCryptographicHash>
#include "configuration.hpp"
#include "exception.hpp"
#include "localization.hpp"

using namespace Huggle;

QString Generic::Bool2String(bool b)
{
    if (b)
        return "true";
    return "false";
}

bool Generic::SafeBool(QString value, bool defaultvalue)
{
    value = value.toLower();
    if (value == "true")
    {
        return true;
    } else if (value == "false")
    {
        return false;
    }
    return defaultvalue;
}

QStringList Generic::CSV2QStringList(QString CSV, QChar separator)
{
    QStringList result;
    foreach(QString x, CSV.split(separator))
    {
        // Trim whitespace around the string, in case users used some extra spaces when separating CSV
        x = x.trimmed();
        // Remove the extra newline which could be present in last element
        x = x.replace("\n", "");
        if (!x.isEmpty())
        {
            // only use these items that contain something
           result.append(x);
        }
    }
    return result;
}

bool Generic::ReportPreFlightCheck()
{
    if (!Configuration::HuggleConfiguration->AskUserBeforeReport)
        return true;
    QMessageBox::StandardButton q = QMessageBox::question(nullptr, _l("report-tu"), _l("report-warn"), QMessageBox::Yes|QMessageBox::No);
    return (q != QMessageBox::No);
}

QString Generic::SanitizePath(QString name)
{
    QString new_name = name;
    while (new_name.contains("//"))
        new_name = new_name.replace("//", "/");
#ifdef HUGGLE_WIN
    return new_name.replace("/", "\\");
#else
    return name;
#endif // HUGGLE_WIN
}

QString Generic::SocketError2Str(QAbstractSocket::SocketError error)
{
    switch (error)
    {
        case QAbstractSocket::ConnectionRefusedError:
            return "Connection refused";
        case QAbstractSocket::RemoteHostClosedError:
            return "Remote host closed the connection unexpectedly";
        case QAbstractSocket::HostNotFoundError:
            return "Host not found";
        case QAbstractSocket::SocketAccessError:
            return "Socket access error";
        case QAbstractSocket::SocketResourceError:
            return "Socket resource error";
        case QAbstractSocket::SocketTimeoutError:
            return "Socket timeout error";
        case QAbstractSocket::DatagramTooLargeError:
            return "Datagram too large";
        case QAbstractSocket::NetworkError:
            return "Network error";
        case QAbstractSocket::AddressInUseError:
            return "AddressInUseError";
        case QAbstractSocket::SocketAddressNotAvailableError:
            return "SocketAdddressNotAvailableError";
        case QAbstractSocket::UnsupportedSocketOperationError:
            return "UnsupportedSocketOperationError";
        case QAbstractSocket::UnfinishedSocketOperationError:
            return "UnfinishedSocketOperationError";
        case QAbstractSocket::ProxyAuthenticationRequiredError:
            return "ProxyAuthenticationRequiredError";
        case QAbstractSocket::SslHandshakeFailedError:
            return "SslHandshakeFailedError";
        case QAbstractSocket::ProxyConnectionRefusedError:
            return "ProxyConnectionRefusedError";
        case QAbstractSocket::ProxyConnectionClosedError:
            return "ProxyConnectionClosedError";
        case QAbstractSocket::ProxyConnectionTimeoutError:
            return "ProxyConnectionTimeoutError";
        case QAbstractSocket::ProxyNotFoundError:
            return "ProxyNotFoundError";
        case QAbstractSocket::ProxyProtocolError:
            return "ProxyProtocolError";
#ifdef HUGGLE_QTV5
        case QAbstractSocket::OperationError:
            return "OperationError";
        case QAbstractSocket::SslInternalError:
            return "SslInternalError";
        case QAbstractSocket::SslInvalidUserDataError:
            return "SslInvalidUserDataError";
        case QAbstractSocket::TemporaryError:
            return "TemporaryError";
#endif
        case QAbstractSocket::UnknownSocketError:
            return "UnknownError";
    }
    return "Unknown";
}

void Generic::DeveloperError()
{
    Generic::MessageBox("Function is restricted now", "You can't perform this action in"\
                        " developer mode, because you aren't logged into the wiki");
}

QString Generic::ShrinkText(QString text, unsigned int size, bool html, unsigned int minimum)
{
    if (size < minimum)
    {
        throw new Huggle::Exception("Parameter size must be more than 2", BOOST_CURRENT_FUNCTION);
    }
    // let's copy the text into new variable so that we don't break the original
    // who knows how these mutable strings are going to behave in qt :D
    QString text_ = text;
    unsigned int length = (unsigned int)text_.length();
    if (length > size)
    {
        text_ = text_.mid(0, size - minimum);
        unsigned int cd = minimum;
        while (cd > 0)
        {
            text_ = text_ + ".";
            cd--;
        }
    } else while ((unsigned int)text_.length() < size)
    {
        text_ += " ";
    }
    if (html)
    {
        text_.replace(" ", "&nbsp;");
    }
    return text_;
}

int Generic::MessageBox(QString title, QString text, MessageBoxStyle st, bool enforce_stop, QWidget *parent)
{
    QMessageBox *mb = new QMessageBox(parent);
    mb->setWindowTitle(title);
    mb->setText(text);
    int return_value = -1;
    switch (st)
    {
        case MessageBoxStyleQuestion:
            mb->setIcon(QMessageBox::Question);
            mb->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            mb->setDefaultButton(QMessageBox::Yes);
            return_value = mb->exec();
            break;
        case MessageBoxStyleQuestionAbort:
            mb->setIcon(QMessageBox::Question);
            mb->setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            mb->setDefaultButton(QMessageBox::Cancel);
            return_value = mb->exec();
            break;
        case MessageBoxStyleNormal:
            mb->setIcon(QMessageBox::Information);
            goto exec;
        case MessageBoxStyleError:
            mb->setIcon(QMessageBox::Critical);
            goto exec;
        case MessageBoxStyleWarning:
            mb->setIcon(QMessageBox::Warning);
            goto exec;
    }
    delete mb;
    return return_value;
    exec:
        if (enforce_stop)
        {
            return_value = mb->exec();
            delete mb;
        }
        else
        {
            mb->setAttribute(Qt::WA_DeleteOnClose, true);
            mb->show();
        }
        return return_value;
}

int Generic::pMessageBox(QWidget *parent, QString title, QString text, MessageBoxStyle st, bool enforce_stop)
{
    return Generic::MessageBox(title, text, st, enforce_stop, parent);
}

QString Generic::IRCQuitDefaultMessage()
{
    return "Huggle (" + hcfg->HuggleVersion + "), the anti vandalism software. See #huggle on irc://chat.freenode.net";
}

QString Generic::HtmlEncode(QString text)
{
    QString encoded;
    for(int i=0;i<text.size();++i)
    {
        QChar ch = text.at(i);
        if(ch.unicode() > 255)
            encoded += QString("&#%1;").arg((int)ch.unicode());
        else
            encoded += ch;
    }
    encoded = encoded.replace("<", "&lt;");
    encoded = encoded.replace(">", "&gt;");
    return encoded;
}

QString Generic::MD5(QString data)
{
    return QString(QCryptographicHash::hash(data.toUtf8(), QCryptographicHash::Md5).toHex());
}
