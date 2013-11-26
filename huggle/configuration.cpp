//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "configuration.hpp"

using namespace Huggle;

Configuration * Configuration::HuggleConfiguration = new Configuration();

Configuration::Configuration()
{
    this->AIVP = NULL;
    this->UAAP = NULL;
    this->Verbosity = 0;
    this->Project = new WikiSite("enwiki", "en.wikipedia.org/", "wiki/", "w/", true, true, "#en.wikipedia", "en");
    this->UsingSSL = true;
    this->UserName = "User";
    this->Password = "";
    this->WelcomeMP = "Project:Huggle/Message";
#ifdef PYTHONENGINE
    this->PythonEngine = true;
#else
    this->PythonEngine = false;
#endif
    //! This is a consumer key for "huggle" on wmf wikis
    this->WmfOAuthConsumerKey = "56a6d6de895e3b859faa57b677f6cd21";
    this->Cache_InfoSize = 200;
    this->Restricted = false;
    this->ProviderCache = 200;
    this->HuggleVersion = HUGGLE_VERSION;
    this->UsingIRC = true;
    this->IRCIdent = "huggle";
    this->IRCServer = "irc.wikimedia.org";
    this->IRCNick = "huggle";
    this->IRCPort = 6667;
    this->RingLogMaxSize = 2000;
    this->HomePath = QDir::currentPath();
    this->UpdatesEnabled = true;
    this->EditSuffixOfHuggle = "([[WP:HG|HG 3]])";
    this->WikiDB = "";
    this->DefaultRevertSummary = "Reverted edits by $1 identified as vandalism";
    this->Platform = HUGGLE_UPDATER_PLATFORM_TYPE;

    // Global
    this->GlobalConfigurationWikiAddress = "meta.wikimedia.org/w/";
    this->GlobalConfig_EnableAll = true;
    this->GlobalConfig_MinVersion = HUGGLE_VERSION;
    this->GlobalConfig_LocalConfigWikiPath = "Project:Huggle/Config";
    this->GlobalConfig_DocumentationPath = "https://www.mediawiki.org/wiki/Manual:Huggle";
    this->GlobalConfig_FeedbackPath = "http://en.wikipedia.org/wiki/Wikipedia:Huggle/Feedback";
    this->GlobalConfig_UserConf = "User:$1/huggle.css";

    // Local
    this->LocalConfig_MinimalVersion = "3.0.0.0";
    this->LocalConfig_UseIrc = false;
    this->LocalConfig_RequireRollback = false;
    this->LocalConfig_RequireAdmin = false;
    this->LocalConfig_ConfirmOnSelfRevs = true;
    this->LocalConfig_ConfirmWL = true;
    this->LocalConfig_ConfirmTalk = true;
    this->LocalConfig_EnableAll = false;
    this->LocalConfig_RequireEdits = 0;
    this->LocalConfig_ScoreTalk = -800;
    this->LocalConfig_AssociatedDelete = "G8. Page dependent on a non-existent or deleted page.";
    this->LocalConfig_DeletionSummary = "Deleted page using Huggle";
    this->LocalConfig_DeletionTemplate = "{{subst:Deleted}}";
    this->LocalConfig_DeletionTitle = "Your page was deleted";

    // Reverting
    this->LocalConfig_MultipleRevertSummary = "Reverted,edit by,edits by,and,other users,to last revision by,to an older version by";
    this->LocalConfig_RollbackSummary = "Reverted edits by [[Special:Contributions/$1|$1]] ([[User talk:$1|talk]]) to last revision by $2";
    this->LocalConfig_DefaultSummary = "Reverted edits by [[Special:Contributions/$1|$1]] ([[User talk:$1|talk]]) to last revision by $2";
    this->LocalConfig_SingleRevert = "Reverted edits by [[Special:Contributions/$1|$1]] ([[User talk:$1|talk]])";
    this->LocalConfig_UndoSummary = "Undid edit by [[Special:Contributions/$1|$1]] ([[User talk:$1|talk]])";
    this->LocalConfig_SoftwareRevertDefaultSummary = "Reverted edits by [[Special:Contributions/$1|$1]] ([[User talk:$1|talk]]) to last revision by $2 using huggle software rollback (reverted by $3 revisions to revision $4)";

    // Warnings

    this->LocalConfig_AgfRevert = "Reverted good faith edits";
    this->LocalConfig_WarnSummary = "Warning (level 1)";
    this->LocalConfig_WarnSummary2 = "Warning (level 2)";
    this->LocalConfig_WarnSummary3 = "Warning (level 3)";
    this->LocalConfig_WarnSummary4 = "Warning (level 4)";

    this->QueryListTimeLimit = 2;
    this->HistorySize = 20;

    this->LocalConfig_IPScore = 800;
    this->LocalConfig_ForeignUser = 800;
    this->LocalConfig_BotScore = -200;
    this->LocalConfig_ScoreUser = -600;
    this->LocalConfig_WarningScore = 2000;
    this->LocalConfig_TalkPageWarningScore = -800;
    this->LocalConfig_ScoreFlag = -20000;
    this->WarnUserSpaceRoll = true;
    this->NextOnRv = true;
    this->LocalConfig_WelcomeGood = true;
    this->LocalConfig_ClearTalkPageTemp = "{{Huggle/Cleared}}";
    this->LocalConfig_WelcomeAnon = "{{subst:Welcome-anon}} ~~~~";
    this->GlobalConfigWasLoaded = false;
    this->LocalConfig_GlobalRequired = true;
    this->LocalConfig_AIV = false;
    this->LocalConfig_AIVExtend = true;
    this->LocalConfig_ReportPath = "";
    this->LocalConfig_ReportSt = 0;
    this->LocalConfig_RUTemplateReport = "";
    this->LocalConfig_IPVTemplateReport = "";
    this->LocalConfig_WhitelistScore = -800;
    this->RvCounter = 0;
    this->TrimOldWarnings = true;
    this->EditCounter = 0;
    this->AskUserBeforeReport = true;
    this->QueueNewEditsUp = false;
    this->LocalConfig_WelcomeSummary = "Welcoming user";
    this->LocalConfig_WelcomeTitle = "Welcome";
    this->WelcomeEmpty = true;
    this->LocalConfig_ReportSummary = "Reporting user";
    this->_SafeMode = false;
    this->IRCConnectionTimeOut = 2;

    this->LocalConfig_NSProject = MEDIAWIKI_DEFAULT_NS_PROJECT;
    this->LocalConfig_NSProjectTalk = MEDIAWIKI_DEFAULT_NS_PROJECTTALK;
    this->LocalConfig_NSTalk = MEDIAWIKI_DEFAULT_NS_TALK;
    this->LocalConfig_NSUser = MEDIAWIKI_DEFAULT_NS_USER;
    this->LocalConfig_NSUserTalk = MEDIAWIKI_DEFAULT_NS_USERTALK;
    this->LocalConfig_NSFile = MEDIAWIKI_DEFAULT_NS_FILE;
    this->LocalConfig_NSFileTalk = MEDIAWIKI_DEFAULT_NS_FILETALK;
    this->LocalConfig_NSCategory = MEDIAWIKI_DEFAULT_NS_CATEGORY;
    this->LocalConfig_NSCategoryTalk = MEDIAWIKI_DEFAULT_NS_CATEGORYTALK;
    this->LocalConfig_NSMediaWiki = MEDIAWIKI_DEFAULT_NS_MEDIAWIKI;
    this->LocalConfig_NSMediaWikiTalk = MEDIAWIKI_DEFAULT_NS_MEDIAWIKITALK;
    this->LocalConfig_NSHelp = MEDIAWIKI_DEFAULT_NS_HELP;
    this->LocalConfig_NSHelpTalk = MEDIAWIKI_DEFAULT_NS_HELPTALK;
    this->LocalConfig_NSPortal = MEDIAWIKI_DEFAULT_NS_PORTAL;
    this->LocalConfig_NSPortalTalk = MEDIAWIKI_DEFAULT_NS_PORTALTALK;

    this->LocalConfig_TemplateAge = -30;
    this->LocalConfig_ScoreChange = 100;

    // Blocking users
    this->LocalConfig_BlockTime = "indefinite";
    this->LocalConfig_BlockTimeAnon = "31 hours";
    this->LocalConfig_BlockMessage = "{{subst:huggle/block|1=$1|2=$2}}";
    this->LocalConfig_BlockMessageIndef = "{{subst:huggle/block-indef|1=$1}}";
    this->LocalConfig_BlockReason = "[[WP:VAND|Vandalism]]";
    this->LocalConfig_BlockSummary = "Notification: Blocked";
    this->AutomaticallyResolveConflicts = false;
    this->VandalNw_Server = "hub.tm-irc.org";
    this->VandalNw_Login = true;

    this->LocalConfig_ProtectReason = "Persistent [[WP:VAND|vandalism]]";

    this->LocalConfig_ConfirmMultipleEdits = false;
    this->LocalConfig_ConfirmRange = false;
    this->LocalConfig_ConfirmPage = false;
    this->LocalConfig_ConfirmSame = false;
    this->LocalConfig_ConfirmWarned = false;
    this->FontSize = 10;
    this->WriteTimeout = 200;
    this->ReadTimeout = 60;
    this->EnforceManualSoftwareRollback = false;
    this->WhitelistDisabled = false;

    this->LocalConfig_UAAavailable = false;
    this->LocalConfig_UAAPath = "Project:Usernames for administrator attention";
    this->LocalConfig_UAATemplate = "* {{user-uaa|1=$1}} $2 ~~~~";
    this->RevertOnMultipleEdits = false;
    this->SyslogPath = "huggle.log";
    this->Log2File = false;
}

Configuration::~Configuration()
{
    delete this->AIVP;
    delete this->Project;
    delete this->UAAP;
}

QString Configuration::GetURLProtocolPrefix()
{
    if (!Configuration::HuggleConfiguration->UsingSSL)
    {
        return "http://";
    }
    return "https://";
}

QString Configuration::GetConfigurationPath()
{
    QDir conf(Configuration::HuggleConfiguration->HomePath + QDir::separator() + "Configuration");
    if (!conf.exists())
    {
        conf.mkdir(Configuration::HuggleConfiguration->HomePath + QDir::separator() + "Configuration");
    }
    return Configuration::HuggleConfiguration->HomePath + QDir::separator() + "Configuration" + QDir::separator();
}

QString Configuration::GetDefaultRevertSummary(QString source)
{
    QString summary = Configuration::HuggleConfiguration->DefaultRevertSummary;
    summary = summary.replace("$1", source) + " " + Configuration::HuggleConfiguration->EditSuffixOfHuggle;
    return summary;
}

QString Configuration::Bool2ExcludeRequire(bool b)
{
    if (b)
    {
        return "exclude";
    }
    return "require";
}

QString Configuration::Bool2String(bool b)
{
    if (b)
    {
        return "true";
    }
    return "false";
}

void Configuration::NormalizeConf()
{
    if (Configuration::HuggleConfiguration->LocalConfig_TemplateAge > -1)
    {
        Configuration::HuggleConfiguration->LocalConfig_TemplateAge = -30;
    }
    if (Configuration::HuggleConfiguration->Cache_InfoSize < 10)
    {
        Configuration::HuggleConfiguration->Cache_InfoSize = 10;
    }
    if (Configuration::HuggleConfiguration->HistorySize < 2)
    {
        Configuration::HuggleConfiguration->HistorySize = 2;
    }
    Configuration::HuggleConfiguration->EditCounter = 0;
}


bool Configuration::SafeBool(QString value, bool defaultvalue)
{
    if (value.toLower() == "true")
    {
        return true;
    }
    return defaultvalue;
}

QString Configuration::MakeLocalUserConfig()
{
    QString conf = "<nowiki>\n";
    conf += "enable:true\n";
    conf += "version:" + Configuration::HuggleConfiguration->HuggleVersion + "\n\n";
    conf += "admin:true\n";
    conf += "patrol-speedy:true\n";
    conf += "speedy-message-title:Speedy deleted\n";
    conf += "report-summary:" + Configuration::HuggleConfiguration->LocalConfig_ReportSummary + "\n";
    conf += "prod-message-summary:Notification: Proposed deletion of [[$1]]\n";
    conf += "warn-summary-4:" + Configuration::HuggleConfiguration->LocalConfig_WarnSummary4 + "\n";
    conf += "warn-summary-3:" + Configuration::HuggleConfiguration->LocalConfig_WarnSummary3 + "\n";
    conf += "warn-summary-2:" + Configuration::HuggleConfiguration->LocalConfig_WarnSummary2 + "\n";
    conf += "warn-summary:" + Configuration::HuggleConfiguration->LocalConfig_WarnSummary + "\n";
    conf += "auto-advance:false\n";
    conf += "auto-whitelist:true\n";
    conf += "confirm-multiple:" + Configuration::Bool2String(Configuration::HuggleConfiguration->LocalConfig_ConfirmMultipleEdits) + "\n";
    conf += "confirm-range:" + Configuration::Bool2String(Configuration::HuggleConfiguration->LocalConfig_ConfirmRange) + "\n";
    conf += "// this option will change the behaviour of automatic resolution, be carefull\n";
    conf += "revert-auto-multiple-edits:" + Configuration::Bool2String(Configuration::HuggleConfiguration->RevertOnMultipleEdits) + "\n";
    conf += "automatically-resolve-conflicts:" + Configuration::Bool2String(Configuration::HuggleConfiguration->AutomaticallyResolveConflicts) + "\n";
    conf += "confirm-page:" + Configuration::Bool2String(Configuration::HuggleConfiguration->LocalConfig_ConfirmPage) + "\n";
    conf += "template-age:" + QString::number(Configuration::HuggleConfiguration->LocalConfig_TemplateAge) + "\n";
    conf += "confirm-same:" + Configuration::Bool2String(Configuration::HuggleConfiguration->LocalConfig_ConfirmSame) + "\n";
    conf += "default-summary:" + Configuration::HuggleConfiguration->DefaultRevertSummary + "\n";
    conf += "software-rollback:" + Configuration::Bool2String(Configuration::HuggleConfiguration->EnforceManualSoftwareRollback) + "\n";
    conf += "diff-font-size:" + QString::number(Configuration::HuggleConfiguration->FontSize) + "\n";
    conf += "// queues\nqueues:\n";
    int c = 0;
    while (c < HuggleQueueFilter::Filters.count())
    {
        HuggleQueueFilter *fltr = HuggleQueueFilter::Filters.at(c);
        c++;
        if (fltr->IsChangeable())
        {
            conf += "    " + fltr->QueueName + ":\n";
            conf += "        filter-ignored:" + Configuration::Bool2ExcludeRequire(fltr->getIgnoreWL()) + "\n";
            conf += "        filter-bots:" + Configuration::Bool2ExcludeRequire(fltr->getIgnoreBots()) + "\n";
            conf += "        filter-assisted:" + Configuration::Bool2ExcludeRequire(fltr->getIgnoreFriends()) + "\n";
            conf += "        filter-ip:" + Configuration::Bool2ExcludeRequire(fltr->getIgnoreIP()) + "\n";
            conf += "        filter-minor:" + Configuration::Bool2ExcludeRequire(fltr->getIgnoreMinor()) + "\n";
            conf += "        filter-np:" + Configuration::Bool2ExcludeRequire(fltr->getIgnoreNP()) + "\n";
            conf += "        filter-self:" + Configuration::Bool2ExcludeRequire(fltr->getIgnoreSelf()) + "\n";
            conf += "        filter-users:" + Configuration::Bool2ExcludeRequire(fltr->getIgnoreUsers()) + "\n";
            conf += "\n";
        }
    }
    conf += "</nowiki>";
    return conf;
}

void Configuration::LoadConfig()
{
    QFile file(Configuration::GetConfigurationPath() + "huggle3.xml");
    Huggle::Syslog::HuggleLogs->Log("Home: " + Configuration::GetConfigurationPath());
    if (!QFile().exists(Configuration::GetConfigurationPath() + "huggle3.xml"))
    {
        Huggle::Syslog::HuggleLogs->DebugLog("No config file at " + Configuration::GetConfigurationPath() + "huggle3.xml");
        return;
    }
    if(!file.open(QIODevice::ReadOnly))
    {
        Huggle::Syslog::HuggleLogs->DebugLog("Unable to read config file");
        return;
    }
    QDomDocument conf;
    conf.setContent(file.readAll());
    QDomNodeList l = conf.elementsByTagName("local");
    int item = 0;
    while (item < l.count())
    {
        QDomElement option = l.at(item).toElement();
        item++;
        QDomNamedNodeMap xx = option.attributes();
        if (!xx.contains("text") || !xx.contains("key"))
        {
            continue;
        }
        QString key = option.attribute("key");
        if (key == "DefaultRevertSummary")
        {
            Configuration::HuggleConfiguration->DefaultRevertSummary = option.attribute("text");
            continue;
        }
        if (key == "Cache_InfoSize")
        {
            Configuration::HuggleConfiguration->Cache_InfoSize = option.attribute("text").toInt();
            continue;
        }
        if (key == "GlobalConfigurationWikiAddress")
        {
            Configuration::HuggleConfiguration->GlobalConfigurationWikiAddress = option.attribute("text");
            continue;
        }
        if (key == "IRCIdent")
        {
            Configuration::HuggleConfiguration->IRCIdent = option.attribute("text");
            continue;
        }
        if (key == "IRCNick")
        {
            Configuration::HuggleConfiguration->IRCNick = option.attribute("text");
            continue;
        }
        if (key == "IRCPort")
        {
            Configuration::HuggleConfiguration->IRCPort = option.attribute("text").toInt();
            continue;
        }
        if (key == "IRCServer")
        {
            Configuration::HuggleConfiguration->IRCServer = option.attribute("text");
            continue;
        }
        if (key == "Language")
        {
            Localizations::HuggleLocalizations->PreferredLanguage = option.attribute("text");
            continue;
        }
        if (key == "ProviderCache")
        {
            Configuration::HuggleConfiguration->ProviderCache = option.attribute("text").toInt();
            continue;
        }
        if (key == "AskUserBeforeReport")
        {
            Configuration::HuggleConfiguration->AskUserBeforeReport = Configuration::SafeBool(option.attribute("text"));
            continue;
        }
        if (key == "HistorySize")
        {
            Configuration::HuggleConfiguration->HistorySize = option.attribute("text").toInt();
            continue;
        }
        if (key == "VandalNw_Login")
        {
            Configuration::HuggleConfiguration->VandalNw_Login = Configuration::SafeBool(option.attribute("text"));
            continue;
        }
        if (key == "UserName")
        {
            Configuration::HuggleConfiguration->UserName = option.attribute("text");
            continue;
        }
        if (key == "WarnUserSpaceRoll")
        {
            Configuration::HuggleConfiguration->WarnUserSpaceRoll = Configuration::SafeBool(option.attribute("text"));
            continue;
        }
        if (key == "NextOnRv")
        {
            Configuration::HuggleConfiguration->NextOnRv = Configuration::SafeBool(option.attribute("text"));
            continue;
        }
        if (key == "EnableUpdates")
        {
            Configuration::HuggleConfiguration->UpdatesEnabled = Configuration::SafeBool(option.attribute("text"));
            continue;
        }
    }
    Huggle::Syslog::HuggleLogs->DebugLog("Finished conf");
}

void Configuration::SaveConfig()
{
    QFile file(Configuration::GetConfigurationPath() + QDir::separator() + "huggle3.xml");
    if (!file.open(QIODevice::WriteOnly))
    {
        Huggle::Syslog::HuggleLogs->Log("Unable to save configuration because the file can't be open");
        return;
    }
    QXmlStreamWriter *x = new QXmlStreamWriter();
    x->setDevice(&file);
    x->writeStartDocument();
    x->writeStartElement("huggle");
    Configuration::InsertConfig("Cache_InfoSize", QString::number(Configuration::HuggleConfiguration->Cache_InfoSize), x);
    Configuration::InsertConfig("DefaultRevertSummary", Configuration::HuggleConfiguration->DefaultRevertSummary, x);
    Configuration::InsertConfig("GlobalConfigurationWikiAddress", Configuration::HuggleConfiguration->GlobalConfigurationWikiAddress, x);
    Configuration::InsertConfig("IRCIdent", Configuration::HuggleConfiguration->IRCIdent, x);
    Configuration::InsertConfig("IRCNick", Configuration::HuggleConfiguration->IRCNick, x);
    Configuration::InsertConfig("IRCPort", QString::number(Configuration::HuggleConfiguration->IRCPort), x);
    Configuration::InsertConfig("IRCServer", Configuration::HuggleConfiguration->IRCServer, x);
    Configuration::InsertConfig("Language", Localizations::HuggleLocalizations->PreferredLanguage, x);
    Configuration::InsertConfig("ProviderCache", QString::number(Configuration::HuggleConfiguration->ProviderCache), x);
    Configuration::InsertConfig("AskUserBeforeReport", Configuration::Bool2String(Configuration::HuggleConfiguration->AskUserBeforeReport), x);
    Configuration::InsertConfig("HistorySize", QString::number(Configuration::HuggleConfiguration->HistorySize), x);
    Configuration::InsertConfig("NextOnRv", Configuration::Bool2String(Configuration::HuggleConfiguration->NextOnRv), x);
    Configuration::InsertConfig("QueueNewEditsUp", Configuration::Bool2String(Configuration::HuggleConfiguration->QueueNewEditsUp), x);
    Configuration::InsertConfig("RingLogMaxSize", QString::number(Configuration::HuggleConfiguration->RingLogMaxSize), x);
    Configuration::InsertConfig("TrimOldWarnings", Configuration::Bool2String(Configuration::HuggleConfiguration->TrimOldWarnings), x);
    Configuration::InsertConfig("EnableUpdates", Configuration::Bool2String(Configuration::HuggleConfiguration->UpdatesEnabled), x);
    Configuration::InsertConfig("WarnUserSpaceRoll", Configuration::Bool2String(Configuration::HuggleConfiguration->WarnUserSpaceRoll), x);
    Configuration::InsertConfig("UserName", Configuration::HuggleConfiguration->UserName, x);
    /////////////////////////////
    // Vandal network
    /////////////////////////////
    Configuration::InsertConfig("VandalNw_Login", Configuration::Bool2String(Configuration::HuggleConfiguration->VandalNw_Login), x);
    x->writeEndElement();
    x->writeEndDocument();
    delete x;
}

QStringList Configuration::ConfigurationParse_QL(QString key, QString content, bool CS)
{
    QStringList list;
    if (content.startsWith(key + ":"))
    {
        QString value = content.mid(key.length() + 1);
        QStringList lines = value.split("\n");
        int curr = 1;
        while (curr < lines.count())
        {
            QString _line = HuggleParser::Trim(lines.at(curr));
            if (_line.endsWith(","))
            {
                list.append(_line);
            } else
            {
                if (_line != "")
                {
                    list.append(_line);
                    break;
                }
            }
            curr++;
        }
        if (CS)
        {
            // now we need to split values by comma as well
            QStringList f;
            int c = 0;
            while (c<list.count())
            {
                QStringList xx = list.at(c).split(",");
                int i2 = 0;
                while (i2<xx.count())
                {
                    if (HuggleParser::Trim(xx.at(i2)) != "")
                    {
                        f.append(HuggleParser::Trim(xx.at(i2)));
                    }
                    i2++;
                }
                c++;
            }
            list = f;
        }
        return list;
    } else if (content.contains("\n" + key + ":"))
    {
        QString value = content.mid(content.indexOf("\n" + key + ":") + key.length() + 2);
        QStringList lines = value.split("\n");
        int curr = 1;
        while (curr < lines.count())
        {
            QString _line = HuggleParser::Trim(lines.at(curr));
            if (_line.endsWith(","))
            {
                list.append(_line);
            } else
            {
                if (_line != "")
                {
                    list.append(_line);
                    break;
                }
            }
            curr++;
        }
        if (CS)
        {
            // now we need to split values by comma as well
            QStringList f;
            int c = 0;
            while (c<list.count())
            {
                QStringList xx = list.at(c).split(",");
                int i2 = 0;
                while (i2<xx.count())
                {
                    if (HuggleParser::Trim(xx.at(i2)) != "")
                    {
                        f.append(HuggleParser::Trim(xx.at(i2)));
                    }
                    i2++;
                }
                c++;
            }
            list = f;
        }
        return list;
    }
    return list;
}

QStringList Configuration::ConfigurationParse_QL(QString key, QString content, QStringList list, bool CS)
{
    QStringList result = Configuration::ConfigurationParse_QL(key, content, CS);
    if (result.count() == 0)
    {
        return list;
    }
    return result;
}

QList<HuggleQueueFilter *> Configuration::ConfigurationParseQueueList(QString content, bool locked)
{
    QList<HuggleQueueFilter*> ReturnValue;

    if (!content.contains("queues:"))
    {
        return ReturnValue;
    }

    // we need to parse all blocks that contain information about queue

    content = content.mid(content.indexOf("queues:") + 8);
    QStringList Filtered = content.split("\n");

    QStringList Info;

    // we need to assume that all queues are intended with at least 4 spaces

    int line = 0;

    while (line < Filtered.count())
    {
        QString lt = Filtered.at(line);
        if (lt.startsWith("    ") || lt == "")
        {
            Info.append(lt);
        } else
        {
            // we reached the end of block with queue defs
            break;
        }
        line++;
    }

    // now we can split the queue info

    line = 0;
    while (line < Info.count())
    {
        QString text = Info.at(line);
        if (text.startsWith("    ") && !text.startsWith("        ") && text.contains(":"))
        {
            // this is a queue definition beginning, because it is intended with 4 spaces
            HuggleQueueFilter *filter = new HuggleQueueFilter();
            ReturnValue.append(filter);
            filter->ProjectSpecific = locked;
            QString name = text;
            while (name.startsWith(" "))
            {
                name = name.mid(1);
            }
            name.replace(":", "");
            filter->QueueName = name;
            line++;
            text = Info.at(line);
            while (text.startsWith("        ") && text.contains(":") && line < Info.count())
            {
                // we need to parse the info
                line++;
                while (text.startsWith(" "))
                {
                    text = text.mid(1);
                }
                QString val = text.mid(text.indexOf(":") + 1);
                QString key = text.mid(0, text.indexOf(":"));
                text = Info.at(line);
                if (key == "filter-ignored")
                {
                    if (val == "exclude")
                    {
                        filter->setIgnoreWL(true);
                    } else
                    {
                        filter->setIgnoreWL(false);
                    }
                    continue;
                }
                if (key == "filter-bots")
                {
                    if (val == "exclude")
                    {
                        filter->setIgnoreBots(true);
                    } else
                    {
                        filter->setIgnoreBots(false);
                    }
                    continue;
                }
                if (key == "filter-assisted")
                {
                    if (val == "exclude")
                    {
                        filter->setIgnoreFriends(true);
                    } else
                    {
                        filter->setIgnoreFriends(false);
                    }
                    continue;
                }
                if (key == "filter-ip")
                {
                    if (val == "exclude")
                    {
                        filter->setIgnoreIP(true);
                    } else
                    {
                        filter->setIgnoreIP(false);
                    }
                    continue;
                }
            }
        } else
        {
            line++;
        }
    }

    return ReturnValue;
}

bool Configuration::ParseGlobalConfig(QString config)
{
    Configuration::HuggleConfiguration->GlobalConfig_EnableAll = Configuration::SafeBool(Configuration::ConfigurationParse("enable-all", config));
    QString temp = Configuration::ConfigurationParse("documentation", config);
    if (temp != "")
    {
        Configuration::HuggleConfiguration->GlobalConfig_DocumentationPath = temp;
    }
    temp = Configuration::ConfigurationParse("feedback", config);
    if (temp != "")
    {
        Configuration::HuggleConfiguration->GlobalConfig_FeedbackPath = temp;
    }
    Configuration::HuggleConfiguration->GlobalConfigWasLoaded = true;
    return true;
}

bool Configuration::ParseLocalConfig(QString config)
{
    //AIV
    Configuration::HuggleConfiguration->LocalConfig_AIV = Configuration::SafeBool(Configuration::ConfigurationParse("aiv-reports", config));
    Configuration::HuggleConfiguration->LocalConfig_AIVExtend = Configuration::SafeBool(Configuration::ConfigurationParse("aiv-extend", config));
    Configuration::HuggleConfiguration->LocalConfig_ReportPath = Configuration::ConfigurationParse("aiv", config);
    Configuration::HuggleConfiguration->LocalConfig_ReportSt = Configuration::ConfigurationParse("aiv-section", config).toInt();
    Configuration::HuggleConfiguration->LocalConfig_IPVTemplateReport = Configuration::ConfigurationParse("aiv-ip", config);
    Configuration::HuggleConfiguration->LocalConfig_RUTemplateReport = Configuration::ConfigurationParse("aiv-user", config);
    // Restrictions
    Configuration::HuggleConfiguration->LocalConfig_EnableAll = Configuration::SafeBool(Configuration::ConfigurationParse("enable-all", config));
    Configuration::HuggleConfiguration->LocalConfig_RequireAdmin = Configuration::SafeBool(Configuration::ConfigurationParse("require-admin", config));
    Configuration::HuggleConfiguration->LocalConfig_RequireRollback = Configuration::SafeBool(Configuration::ConfigurationParse("require-rollback", config));
    Configuration::HuggleConfiguration->LocalConfig_RequireEdits = Configuration::ConfigurationParse("require-edits", config, "0").toInt();
    // IRC
    Configuration::HuggleConfiguration->LocalConfig_UseIrc = Configuration::SafeBool(Configuration::ConfigurationParse("irc", config));
    // Ignoring
    Configuration::HuggleConfiguration->LocalConfig_Ignores = Configuration::ConfigurationParse_QL("ignore", config, true);
    Configuration::HuggleConfiguration->LocalConfig_IgnorePatterns = Configuration::ConfigurationParse_QL("ignore-patterns", config);
    // Scoring
    Configuration::HuggleConfiguration->LocalConfig_IPScore = Configuration::ConfigurationParse("score-ip", config, "800").toInt();
    Configuration::HuggleConfiguration->LocalConfig_ScoreFlag = Configuration::ConfigurationParse("score-flag", config).toInt();
    Configuration::HuggleConfiguration->LocalConfig_ForeignUser = Configuration::ConfigurationParse("score-foreign-user", config, "200").toInt();
    Configuration::HuggleConfiguration->LocalConfig_BotScore = Configuration::ConfigurationParse("score-bot", config, "-200000").toInt();
    Configuration::HuggleConfiguration->LocalConfig_ScoreUser = Configuration::ConfigurationParse("score-user", config, "-200").toInt();
    Configuration::HuggleConfiguration->LocalConfig_ScoreTalk = Configuration::ConfigurationParse("score-talk", config, "-800").toInt();
    // Summaries
    Configuration::HuggleConfiguration->LocalConfig_WarnSummary = Configuration::ConfigurationParse("warn-summary", config);
    Configuration::HuggleConfiguration->LocalConfig_WarnSummary2 = Configuration::ConfigurationParse("warn-summary-2", config);
    Configuration::HuggleConfiguration->LocalConfig_DefaultSummary = Configuration::ConfigurationParse("default-summary", config,
              "Reverted edits by [[Special:Contributions/$1|$1]] ([[User talk:$1|talk]]) to last revision by $2");
    Configuration::HuggleConfiguration->LocalConfig_AgfRevert = Configuration::ConfigurationParse("agf", config,
              "Reverted good faith edits by [[Special:Contributions/$2|$2]] [[User talk:$2|talk]]");
    Configuration::HuggleConfiguration->LocalConfig_WarnSummary3 = Configuration::ConfigurationParse("warn-summary-3", config);
    Configuration::HuggleConfiguration->LocalConfig_WarnSummary4 = Configuration::ConfigurationParse("warn-summary-4", config);
    Configuration::HuggleConfiguration->LocalConfig_RevertSummaries = Configuration::ConfigurationParse_QL("template-summ", config);
    Configuration::HuggleConfiguration->LocalConfig_RollbackSummary = Configuration::ConfigurationParse("rollback-summary", config,
              "Reverted edits by [[Special:Contributions/$1|$1]] ([[User talk:$1|talk]]) to last revision by $2");
    Configuration::HuggleConfiguration->LocalConfig_SingleRevert = Configuration::ConfigurationParse("single-revert-summary", config,
              "Undid edit by [[Special:Contributions/$1|$1]] ([[User talk:$1|talk]])");
    Configuration::HuggleConfiguration->LocalConfig_UndoSummary = Configuration::ConfigurationParse("undo-summary", config);
    Configuration::HuggleConfiguration->LocalConfig_SoftwareRevertDefaultSummary = Configuration::ConfigurationParse("manual-revert-summary", config,
              "Reverted edits by [[Special:Contributions/$1|$1]] to last revision by $2");
    Configuration::HuggleConfiguration->LocalConfig_MultipleRevertSummary = Configuration::ConfigurationParse("multiple-revert-summary-parts", config,
              "Reverted,edit by,edits by,and,other users,to last revision by,to an older version by");
    // Warning types
    Configuration::HuggleConfiguration->LocalConfig_WarningTypes = Configuration::ConfigurationParse_QL("warning-types", config);
    Configuration::HuggleConfiguration->LocalConfig_WarningDefs = Configuration::ConfigurationParse_QL("warning-template-tags", config);
    // Reverting
    Configuration::HuggleConfiguration->LocalConfig_ConfirmMultipleEdits = Configuration::SafeBool(Configuration::ConfigurationParse("confirm-multiple", config));
    Configuration::HuggleConfiguration->LocalConfig_ConfirmRange = Configuration::SafeBool(Configuration::ConfigurationParse("confirm-range", config));
    Configuration::HuggleConfiguration->LocalConfig_ConfirmSame = Configuration::SafeBool(Configuration::ConfigurationParse("confirm-same", config));
    Configuration::HuggleConfiguration->LocalConfig_ConfirmWarned = Configuration::SafeBool(Configuration::ConfigurationParse("confirm-warned", config));
    Configuration::HuggleConfiguration->AutomaticallyResolveConflicts = Configuration::SafeBool(Configuration::ConfigurationParse("automatically-resolve-conflicts", config), false);
    // Welcoming
    Configuration::HuggleConfiguration->LocalConfig_WelcomeGood = Configuration::SafeBool(Configuration::ConfigurationParse("welcome-on-good-edit", config, "true"));
    Configuration::HuggleConfiguration->LocalConfig_WelcomeTypes = Configuration::ConfigurationParse_QL("welcome-messages", config);
    // Reporting
    Configuration::HuggleConfiguration->LocalConfig_ReportSummary = Configuration::ConfigurationParse("report-summary", config);
    Configuration::HuggleConfiguration->LocalConfig_SpeedyTemplates = Configuration::ConfigurationParse_QL("speedy-options", config);
    // Parsing
    Configuration::HuggleConfiguration->LocalConfig_TemplateAge = Configuration::ConfigurationParse("template-age", config, QString::number(Configuration::HuggleConfiguration->LocalConfig_TemplateAge)).toInt();
    // UAA
    Configuration::HuggleConfiguration->LocalConfig_UAAPath = Configuration::ConfigurationParse("uaa", config);
    // Blocking
    Configuration::HuggleConfiguration->LocalConfig_BlockMessage = Configuration::ConfigurationParse("block-message", config);
    Configuration::HuggleConfiguration->LocalConfig_BlockReason = Configuration::ConfigurationParse("block-reason", config);
    Configuration::HuggleConfiguration->LocalConfig_BlockSummary = Configuration::ConfigurationParse("block-summary", config, "Notification: Blocked");
    Configuration::HuggleConfiguration->LocalConfig_BlockTime = Configuration::ConfigurationParse("blocktime", config, "indef");
    Configuration::HuggleConfiguration->LocalConfig_ClearTalkPageTemp = Configuration::ConfigurationParse("template-clear-talk-page", config, "{{Huggle/Cleared}}");
    Configuration::HuggleConfiguration->LocalConfig_Assisted = Configuration::ConfigurationParse_QL("assisted-summaries", config);
    Configuration::HuggleConfiguration->LocalConfig_ProtectReason = Configuration::ConfigurationParse("protection-reason", config, "Excessive [[Wikipedia:Vandalism|vandalism]]");
    Configuration::HuggleConfiguration->LocalConfig_RevertPatterns = Configuration::ConfigurationParse_QL("revert-patterns", config);
    Configuration::HuggleConfiguration->RevertPatterns.clear();
    int xx = 0;
    while (xx < Configuration::HuggleConfiguration->LocalConfig_RevertPatterns.count())
    {
        Configuration::HuggleConfiguration->RevertPatterns.append(QRegExp(Configuration::HuggleConfiguration->LocalConfig_RevertPatterns.at(xx)));
        xx++;
    }
    HuggleQueueFilter::Filters += Configuration::ConfigurationParseQueueList(config, true);

    if (Configuration::HuggleConfiguration->AIVP != NULL)
    {
        delete Configuration::HuggleConfiguration->AIVP;
    }

    Configuration::HuggleConfiguration->AIVP = new WikiPage(Configuration::HuggleConfiguration->LocalConfig_ReportPath);
    HuggleParser::ParsePats(config);
    HuggleParser::ParseWords(config);
    QStringList namespaces = Configuration::ConfigurationParse_QL("namespace-names", config, true);
    int NS=0;
    while (namespaces.count() > NS)
    {
        QString line = namespaces.at(NS);
        NS++;

        if (!line.contains(",") || !line.contains(";"))
        {
            continue;
        }

        int ns = line.mid(0, line.indexOf(";")).toInt();
        QString name = line.mid(line.indexOf(";"));

        if (!name.contains(","))
        {
            continue;
        }

        name = name.mid(0, name.indexOf(","));
        QString talk = line.mid(line.indexOf(",") + 1);

        if (talk.endsWith(","))
        {
            talk = talk.mid(0, talk.length() - 1);
        }

        if (talk.contains(";"))
        {
            talk = talk.mid(talk.indexOf(";") + 1);
        }

        switch (ns)
        {
            /// \todo Some NS are missing here
            case MEDIAWIKI_NSID_MAIN:
                Configuration::HuggleConfiguration->LocalConfig_NSTalk = talk;
                break;
            case MEDIAWIKI_NSID_CATEGORY:
                Configuration::HuggleConfiguration->LocalConfig_NSCategory = name;
                Configuration::HuggleConfiguration->LocalConfig_NSCategoryTalk = talk;
                break;
            case MEDIAWIKI_NSID_FILE:
                Configuration::HuggleConfiguration->LocalConfig_NSFile = name;
                Configuration::HuggleConfiguration->LocalConfig_NSFileTalk = talk;
                break;
            case MEDIAWIKI_NSID_HELP:
                Configuration::HuggleConfiguration->LocalConfig_NSHelp = name;
                Configuration::HuggleConfiguration->LocalConfig_NSHelpTalk = talk;
                break;
            case MEDIAWIKI_NSID_MEDIAWIKI:
                Configuration::HuggleConfiguration->LocalConfig_NSMediaWiki = name;
                Configuration::HuggleConfiguration->LocalConfig_NSMediaWikiTalk = talk;
                break;
            case MEDIAWIKI_NSID_PORTAL:
                Configuration::HuggleConfiguration->LocalConfig_NSPortal = name;
                Configuration::HuggleConfiguration->LocalConfig_NSPortalTalk = talk;
                break;
            case MEDIAWIKI_NSID_PROJECT:
                Configuration::HuggleConfiguration->LocalConfig_NSProject = name;
                Configuration::HuggleConfiguration->LocalConfig_NSProjectTalk = talk;
                break;
            case MEDIAWIKI_NSID_USER:
                Configuration::HuggleConfiguration->LocalConfig_NSUser = name;
                Configuration::HuggleConfiguration->LocalConfig_NSUserTalk = talk;
                break;
            case MEDIAWIKI_NSID_TEMPLATE:
                Configuration::HuggleConfiguration->LocalConfig_NSTemplate = name;
                Configuration::HuggleConfiguration->LocalConfig_NSTemplateTalk = talk;
                break;
        }
    }

    if (Configuration::HuggleConfiguration->UAAP != NULL)
    {
        delete Configuration::HuggleConfiguration->UAAP;
    }

    Configuration::HuggleConfiguration->UAAP = new WikiPage(Configuration::HuggleConfiguration->LocalConfig_UAAPath);

    // templates
    int CurrentTemplate=0;
    while (CurrentTemplate<Configuration::HuggleConfiguration->LocalConfig_WarningTypes.count())
    {
        QString type = HuggleParser::GetKeyFromValue(Configuration::HuggleConfiguration->LocalConfig_WarningTypes.at(CurrentTemplate));
        int CurrentWarning = 1;
        while (CurrentWarning <= 4)
        {
            QString xx = Configuration::ConfigurationParse(type + QString::number(CurrentWarning), config);
            if (xx != "")
            {
                Configuration::HuggleConfiguration->LocalConfig_WarningTemplates.append(type + QString::number(CurrentWarning) + ";" + xx);
            }
            CurrentWarning++;
        }
        CurrentTemplate++;
    }
    // sanitize
    if (Configuration::HuggleConfiguration->LocalConfig_ReportPath == "")
    {
        Configuration::HuggleConfiguration->LocalConfig_AIV = false;
    }
    // Do the same for UAA as well
    if (Configuration::HuggleConfiguration->LocalConfig_UAAPath == "")
    {
        Configuration::HuggleConfiguration->LocalConfig_UAAavailable = false;
    }
    return true;
}

bool Configuration::ParseUserConfig(QString config)
{
    Configuration::HuggleConfiguration->LocalConfig_EnableAll = Configuration::SafeBool(Configuration::ConfigurationParse("enable", config));
    Configuration::HuggleConfiguration->LocalConfig_Ignores = Configuration::ConfigurationParse_QL("ignore", config, Configuration::HuggleConfiguration->LocalConfig_Ignores);
    Configuration::HuggleConfiguration->LocalConfig_IPScore = Configuration::ConfigurationParse("score-ip", config, QString::number(Configuration::HuggleConfiguration->LocalConfig_IPScore)).toInt();
    Configuration::HuggleConfiguration->LocalConfig_ScoreFlag = Configuration::ConfigurationParse("score-flag", config, QString::number(Configuration::HuggleConfiguration->LocalConfig_ScoreFlag)).toInt();
    Configuration::HuggleConfiguration->LocalConfig_WarnSummary = Configuration::ConfigurationParse("warn-summary", config, Configuration::HuggleConfiguration->LocalConfig_WarnSummary);
    Configuration::HuggleConfiguration->EnforceManualSoftwareRollback = Configuration::SafeBool(Configuration::ConfigurationParse("software-rollback", config));
    Configuration::HuggleConfiguration->LocalConfig_WarnSummary2 = Configuration::ConfigurationParse("warn-summary-2", config, Configuration::HuggleConfiguration->LocalConfig_WarnSummary2);
    Configuration::HuggleConfiguration->LocalConfig_WarnSummary3 = Configuration::ConfigurationParse("warn-summary-3", config, Configuration::HuggleConfiguration->LocalConfig_WarnSummary3);
    Configuration::HuggleConfiguration->LocalConfig_WarnSummary4 = Configuration::ConfigurationParse("warn-summary-4", config, Configuration::HuggleConfiguration->LocalConfig_WarnSummary4);
    Configuration::HuggleConfiguration->AutomaticallyResolveConflicts = Configuration::SafeBool(Configuration::ConfigurationParse("automatically-resolve-conflicts", config), false);
    Configuration::HuggleConfiguration->LocalConfig_TemplateAge = Configuration::ConfigurationParse("template-age", config, QString::number(Configuration::HuggleConfiguration->LocalConfig_TemplateAge)).toInt();
    Configuration::HuggleConfiguration->LocalConfig_RevertSummaries = Configuration::ConfigurationParse_QL("template-summ", config, Configuration::HuggleConfiguration->LocalConfig_RevertSummaries);
    Configuration::HuggleConfiguration->LocalConfig_WarningTypes = Configuration::ConfigurationParse_QL("warning-types", config, Configuration::HuggleConfiguration->LocalConfig_WarningTypes);
    Configuration::HuggleConfiguration->LocalConfig_ScoreChange = Configuration::ConfigurationParse("score-change", config, QString(Configuration::HuggleConfiguration->LocalConfig_ScoreChange)).toInt();
    Configuration::HuggleConfiguration->LocalConfig_ScoreFlag = Configuration::ConfigurationParse("score-flag", config, QString(Configuration::HuggleConfiguration->LocalConfig_ScoreFlag)).toInt();
    Configuration::HuggleConfiguration->LocalConfig_ScoreUser = Configuration::ConfigurationParse("score-user", config, QString(Configuration::HuggleConfiguration->LocalConfig_ScoreUser)).toInt();
    Configuration::HuggleConfiguration->LocalConfig_ScoreTalk = Configuration::ConfigurationParse("score-talk", config, QString(Configuration::HuggleConfiguration->LocalConfig_ScoreTalk)).toInt();
    Configuration::HuggleConfiguration->LocalConfig_WarningDefs = Configuration::ConfigurationParse_QL("warning-template-tags", config, Configuration::HuggleConfiguration->LocalConfig_WarningDefs);
    Configuration::HuggleConfiguration->LocalConfig_BotScore = Configuration::ConfigurationParse("score-bot", config, QString(Configuration::HuggleConfiguration->LocalConfig_BotScore)).toInt();
    HuggleQueueFilter::Filters += Configuration::ConfigurationParseQueueList(config, false);
    Configuration::NormalizeConf();
    /// \todo Lot of configuration options are missing
    return true;
}

QString Configuration::ConfigurationParse(QString key, QString content, QString missing)
{
    if (content.startsWith(key + ":"))
    {
        QString value = content.mid(key.length() + 1);
        if (value.contains("\n"))
        {
            value = value.mid(0, value.indexOf("\n"));
        }
        return value;
    }

    // make sure it's not inside of some string
    if (content.contains("\n" + key + ":"))
    {
        QString value = content.mid(content.indexOf("\n" + key + ":") + key.length() + 2);
        if (value.contains("\n"))
        {
            value = value.mid(0, value.indexOf("\n"));
        }
        return value;
    }
    return missing;
}

void Configuration::InsertConfig(QString key, QString value, QXmlStreamWriter *s)
{
    s->writeStartElement("local");
    s->writeAttribute("key", key);
    s->writeAttribute("text", value);
    s->writeEndElement();
}

ScoreWord::ScoreWord(QString Word, int Score)
{
    this->score = Score;
    this->word = Word;
}

ScoreWord::ScoreWord(ScoreWord *word)
{
    this->score = word->score;
    this->word = word->word;
}

ScoreWord::ScoreWord(const ScoreWord &word)
{
    this->score = word.score;
    this->word = word.word;
}
