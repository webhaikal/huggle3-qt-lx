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

#ifndef HUGGLEFEEDPROVIDERWS_HPP
#define HUGGLEFEEDPROVIDERWS_HPP

#include "definitions.hpp"
#ifdef PYTHONENGINE
#include <Python.h>
#endif

#include <QList>
#include <QTimer>
#include "hugglefeed.hpp"

namespace Huggle
{
    class WikiEdit;
    class HuggleFeedProviderWS : public HuggleFeed
    {
        public:
            HuggleFeedProviderWS();
            ~HuggleFeedProviderWS();
            WikiEdit *RetrieveEdit();
            QString ToString();
        private:
            QList<WikiEdit*> DB;
    };
}

#endif // HUGGLEFEEDPROVIDERWS_HPP
