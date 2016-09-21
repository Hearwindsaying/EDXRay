#pragma once

#include "EDXPrerequisites.h"
#include "../Core/Integrator.h"
#include "../Core/Sampler.h"


namespace EDX
{
	namespace RayTracer
	{
		class PathTracingIntegrator : public Integrator
		{
		private:
			uint mMaxDepth;
			SampleOffsets mpLightSampleOffsets;
			SampleOffsets mpBSDFSampleOffsets;
			SampleOffsets mpScatterOffsets;

		public:
			PathTracingIntegrator(int depth)
				: mMaxDepth(depth)
			{
			}
			~PathTracingIntegrator()
			{
			}

		public:
			Color Li(const RayDifferential& ray, const Scene* pScene, Sampler* pSampler, RandomGen& random, MemoryPool& memory) const;
			void RequestSamples(const Scene* pScene, SampleBuffer* pSampleBuf);
		};
	}
}