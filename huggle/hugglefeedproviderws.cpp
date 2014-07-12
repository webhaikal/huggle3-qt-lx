// IMPORTANT: this file has a different license than rest of huggle

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Lesser General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Lesser General Public License for more details.

// Copyright (c) Petr Bena 2014

#include "hugglefeedproviderws.hpp"
#include <QtWebSockets/QtWebSockets>
#include "configuration.hpp"
#include "exception.hpp"
#include "syslog.hpp"
#include "wikiedit.hpp"
using namespace Huggle;

HuggleFeedProviderWS::HuggleFeedProviderWS()
{

}

HuggleFeedProviderWS::~HuggleFeedProviderWS()
{
    while (this->DB.count() > 0)
    {
        this->DB.at(0)->DecRef();
        this->DB.removeAt(0);
    }
}

WikiEdit *HuggleFeedProviderWS::RetrieveEdit()
{
    if (this->DB.count() > 0)
    {
        WikiEdit *edit = this->DB.at(0);
        this->DB.removeAt(0);
        return edit;
    }
    return nullptr;
}

QString HuggleFeedProviderWS::ToString()
{
    return "WebSockets.IO";
}
