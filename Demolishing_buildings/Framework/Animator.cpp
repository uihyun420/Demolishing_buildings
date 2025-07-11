#include "stdafx.h"
#include "Animator.h"

const std::string Animator::emptyString = "";

void Animator::AddEvent(const std::string& id, int frame, std::function<void()> action)
{
	auto key = std::pair<std::string, int>(id, frame);
	auto it = events.find(key);
	if (it == events.end())
	{
		events.insert({ key, {id, frame} });
	}
	events[key].actions.push_back(action);
}

void Animator::Update(float dt)
{
	if (!isPlaying)
		return;

	accumTime += dt * std::fabs(speed);
	if (accumTime < frameDuration)
		return;

	currentFrame += speed > 0.f ? 1 : -1;
	accumTime = 0.f;

	if (currentFrame == checkFrame)
	{
		if (!playQueue.empty())
		{
			std::string clipId = playQueue.front();
			Play(clipId, false);
			playQueue.pop();
			return;
		}

		switch (currentClip->loopType)
		{
		case AnimationLoopTypes::Single:
			currentFrame = speed > 0.f ? totalFrame - 1 : 0;
			break;
		case AnimationLoopTypes::Loop:
			currentFrame = speed > 0.f ? 0 : totalFrame - 1;
			break;
		}
	}

	SetFrame(currentClip->frames[currentFrame]);
	auto find = events.find({ currentClip->id, currentFrame });
	if (find != events.end())
	{
		auto& ev = find->second;
		for (auto& action : ev.actions)
		{
			if (action)
			{
				action();
			}
		}
	}
}

void Animator::Play(const std::string& clipId, bool clearQueue)
{
	Play(&ANI_CLIP_MGR.Get(clipId), clearQueue);
}

void Animator::Play(AnimationClip* clip, bool clearQueue)
{
	if (clearQueue)
	{
		while (!playQueue.empty())
		{
			playQueue.pop();
		}
	}

	isPlaying = true;

	currentClip = clip;
	totalFrame = clip->frames.size();
	checkFrame = this->speed > 0.f ? totalFrame : -1;
	currentFrame = speed > 0.f ? 0 : totalFrame - 1;

	frameDuration = 1.f / clip->fps;
	accumTime = 0.f;
	SetFrame(currentClip->frames[currentFrame]);
}

void Animator::PlayQueue(const std::string& clipId)
{
	playQueue.push(clipId);
}

void Animator::Stop()
{
	isPlaying = false;
}

void Animator::SetFrame(const AnimationFrame& frame)
{
	sprite->setTexture(TEXTURE_MGR.Get(frame.texId));
	sprite->setTextureRect(frame.texCoord);
	//sprite->
}
