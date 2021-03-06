#pragma once

#include "SteeringBehavior.h"
#include "Agent.h"
#include "SeekBehavior.h"

namespace JimmyGod::AI
{
	class PursuitBehavior : public JimmyGod::AI::SteeringBehavior
	{
	public:
		JimmyGod::Math::Vector2 Calculate(Agent& agent) override;
	};
}