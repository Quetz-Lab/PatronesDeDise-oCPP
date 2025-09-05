#include "AudioSystem.h"

AudioSystem::AudioSystem()
{
	pendingCount = 0;
}

void AudioSystem::RequestSound(SoundEvent event)
{
	if (pendingCount < MAX_PENDING)
	{
		pendingSounds[pendingCount++] = event.id;
	}
}

void AudioSystem::processEvents()
{
	for (int i = 0; i < pendingCount; ++i)
	{
		// Aquí iría la lógica para reproducir el sonido correspondiente
		switch (pendingSounds[i])
		{
		case SoundID::HIT:
			std::cout << "Reproduciendo sonido de HIT" << std::endl;
			break;
		case SoundID::JUMP:
			std::cout << "Reproduciendo sonido de JUMP" << std::endl;
			break;
		case SoundID::DEATH:
			std::cout << "Reproduciendo sonido de DEATH" << std::endl;
			break;
		default:
			break;
		}
	}
	pendingCount = 0; // Limpiar la cola después de procesar
}
