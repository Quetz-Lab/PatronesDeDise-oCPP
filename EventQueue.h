#pragma once
	struct SoundEvent
	{
		SoundID id;
		bool operator==(const SoundEvent& other) const
		{
			return id == other.id;
		}
	};
class EventQueue
{
};
enum class SoundID
{
	HIT, JUMP, DEATH
};
