#pragma once
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
	//std::vecctor<rbx::instance_t> get_children();
	//rbx::instance_t find_first_child();
	//rbx::instance_t find_first_child_by_class();
};
struct instance_t : public nameable_t public interface_t
{
	using nameable::nameable_t;

	
}
