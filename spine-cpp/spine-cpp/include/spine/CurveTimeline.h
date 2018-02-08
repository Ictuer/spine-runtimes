/******************************************************************************
 * Spine Runtimes Software License v2.5
 *
 * Copyright (c) 2013-2016, Esoteric Software
 * All rights reserved.
 *
 * You are granted a perpetual, non-exclusive, non-sublicensable, and
 * non-transferable license to use, install, execute, and perform the Spine
 * Runtimes software and derivative works solely for personal or internal
 * use. Without the written permission of Esoteric Software (see Section 2 of
 * the Spine Software License Agreement), you may not (a) modify, translate,
 * adapt, or develop new applications using the Spine Runtimes or otherwise
 * create derivative works or improvements of the Spine Runtimes or (b) remove,
 * delete, alter, or obscure any trademarks or any copyright, trademark, patent,
 * or other intellectual property or proprietary rights notices on or in the
 * Software, including any copy thereof. Redistributions in binary or source
 * form must include this license and terms.
 *
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ESOTERIC SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, BUSINESS INTERRUPTION, OR LOSS OF
 * USE, DATA, OR PROFITS) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#ifndef Spine_CurveTimeline_h
#define Spine_CurveTimeline_h

#include <spine/Timeline.h>
#include <spine/Vector.h>

#include <assert.h>

namespace Spine {
    /// Base class for frames that use an interpolation bezier curve.
    class CurveTimeline : public Timeline {
        RTTI_DECL;
        
    public:
        CurveTimeline(int frameCount);
        
        virtual void apply(Skeleton& skeleton, float lastTime, float time, Vector<Event*>* pEvents, float alpha, MixPose pose, MixDirection direction) = 0;
        
        virtual int getPropertyId() = 0;
        
        int getFrameCount();
        
        void setLinear(int frameIndex);
        
        void setStepped(int frameIndex);
        
        /// Sets the control handle positions for an interpolation bezier curve used to transition from this keyframe to the next.
        /// cx1 and cx2 are from 0 to 1, representing the percent of time between the two keyframes. cy1 and cy2 are the percent of
        /// the difference between the keyframe's values.
        void setCurve(int frameIndex, float cx1, float cy1, float cx2, float cy2);
        
        float getCurvePercent(int frameIndex, float percent);
        
        float getCurveType(int frameIndex);
        
    protected:
        static const float LINEAR;
        static const float STEPPED;
        static const float BEZIER;
        static const int BEZIER_SIZE;
        
    private:
        Vector<float> _curves; // type, x, y, ...
    };
}

#endif /* Spine_CurveTimeline_h */