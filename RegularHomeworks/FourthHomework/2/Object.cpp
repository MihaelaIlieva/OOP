#include "Object.hpp"

Object::Object(const std::string& name, const std::string& location, const std::string& extension) :
	name(name),location(location), extension(extension)
{
}

std::string Object::get_name() const
{
	return this->name;
}

std::string Object::get_location() const
{
	return this->location;
}

std::string Object::get_extension() const
{
	return this->extension;
}

std::string Object::get_fullpath() const
{
	string fullPath = location;
	fullPath += "/";
	fullPath += name;
	fullPath += ".";
	fullPath += extension;
	return fullPath;
}

bool Object::operator==(const Comparable* other) const
{
	const Object* newObject = dynamic_cast<const Object*>(other);
	if (this->name == newObject->get_name() && this->location == newObject->get_location() &&
		this->extension == newObject->get_extension()) {
		return true;
	}
	return false;
}

bool Object::operator!=(const Comparable* other) const
{
	const Object* newObject = dynamic_cast<const Object*>(other);
	if (this->name == newObject->get_name() && this->location == newObject->get_location() &&
		this->extension == newObject->get_extension()) {
		return false;
	}
	return true;
}

