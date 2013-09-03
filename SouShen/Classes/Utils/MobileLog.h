#ifndef _MOBILELOG_H_
#define _MOBILELOG_H_
#include "System/Logger.h"
#include "Singleton.h"
namespace Utils
{
	class MobileLog
	{
	public:
		MobileLog()
		{
			if(_log == NULL)  
			{
				_log = new System::Logger("/log/mobile");
			}
		}
	   ~MobileLog() 
		{ 
			if(_log != NULL)
				delete _log;
		}
	public:
		System::Logger* getLog() { return _log; }
	private:
		DECLARE_SINGLETON_CLASS(MobileLog);
	private:
		System::Logger *_log;
	};
	typedef Singleton<MobileLog> _gamemanager;
}

#define FATALLOG Utils::_gamemanager::instance()->getLog(System::LogFatal)
#define ERRORLOG Utils::_gamemanager::instance()->getLog(System::LogError)
#define DEBUGLOG Utils::_gamemanager::instance()->getLog(System::LogDebug)
#define INFOLOG  Utils::_gamemanager::instance()->getLog(System::LogInfo)
#define TRACELOG Utils::_gamemanager::instance()->getLog(System::LogTrace)
#endif