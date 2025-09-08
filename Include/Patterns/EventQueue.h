#pragma once
/**
 * @file EventQueue.h
 * @brief Definición de eventos de sonido y cola de eventos.
 *
 * @details
 * Este archivo define:
 * - `SoundID`: identificadores de sonidos básicos.
 * - `SoundEvent`: estructura que encapsula un evento de sonido.
 * - `EventQueue`: clase que actuará como sistema de encolado de eventos.
 *
 * @note Actualmente `EventQueue` está vacío; se espera implementar almacenamiento
 * y despacho de `SoundEvent` en futuras versiones.
 */

 /**
  * @enum SoundID
  * @brief Identificadores únicos para sonidos reproducibles.
  */
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
