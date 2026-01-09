#include <cstdint>
#include <chrono>
#include <thread>
#include <memory/memory.h>
#include <sdk/offset.h>
#include <sdk/sdk.h>
std::int32_t main()
{
	static const char* BINARY_NAME = "RobloxPlayerBeta.exe";

	if (!memory->find_process_id("BINARY_NAME"))
	{
		printf("Unabled to find Roblox!\n");
		std::this_thread::sleep_for(std::chrono::seconds(5));
		return 1;
	}
	if (!memory->attach_to_process("BINARY_NAME")) 
	{
		printf("Unabled to attach to  Roblox!\n");
		std::this_thread::sleep_for(std::chrono::seconds(5));
			return 1;
	}
	if (!memory->find_module_address(BINARY_NAME))
	{
		printf("Unabled to find maind module address !\n");
		std::this_thread::sleep_for(std::chrono::seconds(5));
		return 1; 
	}


	printf("base -> %llx\n", memory->get_module_address());

	std::uint64_t fake_datatmodel= memory->read<std::uint64_t>(memory->get_module_address() + Offsets::FakeDataModel::Pointer);
	std::instance_t data_model = rbx ::instance_t(memory->read<std::uint64_t>(fake_datatmodel + Offsets::FakeDataModel::RealDataModel));
	printf("data model -> 0x%llx\n", data_model);

	std::uint64_t visual = memory->read<std::uint64_t>(memory->get_module_address() + Offsets::VisualEngine::Pointer);
	printf("visualengine -> 0x%llx\n", visual);

	printf("\n%s, %s\n", datamodle.get_name().c_str(), datamodel.get_class_name()._c_str());

} 
