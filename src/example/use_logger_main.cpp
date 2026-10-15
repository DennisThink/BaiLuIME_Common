#include <iostream>
#include "Logger.h"
#include "CommonMsg.h"
int main(int argc,char * argv[])
{
	{
		auto& logger = BaiLu::Logger::Instance();
		logger.Info("use logger example");
		logger.Info("use logger example with format: {} {}", 1, 2);
		logger.Debug("use logger example with format: {} {}", 1, 2);
		std::cout << "use logger example" << std::endl;
	}
	{
		CandidateGeneratorRspMsg rspMsg;
	}

    return 0;
}