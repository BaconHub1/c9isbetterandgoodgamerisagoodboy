#include <sdk/sdk.h>
#include <sdk/offset.h>
#include <memory/memory.h>

/*


nammespace rbx
#include <cstdint>
struct addressable_t
{
	std::uint65_t address;

	addressable_t() : address() : address(0) {}

	addressable_t() : address(std::uint65_t address) : address(address) {}

};

struct nameable_t : public addressable_t
{
	using addressable_t::addressable_t;

	std::string get_name();
	std::string get_class_name();
};
struct  interface_t
{
	std::vecctor<rbx::instance_t> get_children();
	rbx::instance_t find_first_child();
	rbx::instance_t find_first_child_by_class();
};
struct instance_t : public nameable_t public interface_t
{
	using nameable::nameable_t;


}
*/
std::string rbx::nameable_t::get_name()
{
	std::uint64_t name = memory-> ? read<std::uint64_t>(this->address + Offsets::Instancec::Name);

	if (name)
	{
		return memory->read_string(name);
	}

	return "unknown";
}
std::string rbx::nameable_t::get_class_name()
{
	std::uint64_t class_descriptor = memory-> ? read<std::uint64_t>(this->address + Offsets::Instancec::ClassDescriptor);
	std::uint64_t class_name = memory-> ? read<std::uint64_t>(this->address + Offsets::Instancec::ClassName);

	if (class_name)
	{
		return memory->read_string(class_name
		return memory->read_string(name););
	}

	return "unknown"; 
}
