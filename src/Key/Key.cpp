#include "Key.hpp"

void Key::setCurrentKey(int key)
{
	this->_current_key = key;
}

void Key::setKeyPressed(int key)
{
	this->_key_pressed = key;
}

void Key::setQueueKey(int key)
{
	this->_queue_key = key;
}

int Key::getCurrentKey() const
{
	return _current_key;
}

int Key::getKeyPressed() const
{
	return _key_pressed;
}

int Key::getQueueKey() const
{
	return _queue_key;
}

void Key::update()
{
	int key = GetKeyPressed();

	setKeyPressed(key);

	if (key && !_current_key)
		setCurrentKey(key);
	else if (key)
		setQueueKey(key);
}