//==============================================================================
// unitactionunhitch.h
// Copyright (c) 2006-2007 Ensemble Studios
//==============================================================================

#pragma once
#include "action.h"

class BUnit;

//==============================================================================
//==============================================================================
class BUnitActionUnhitch : public BAction
{
public:

   BUnitActionUnhitch() {}
   virtual ~BUnitActionUnhitch() {}

   //Connect/disconnect.
   virtual bool               connect(BEntity* pOwner, BSimOrder* pOrder);
   virtual void               disconnect();
   //Init.
   virtual bool               init();

   virtual bool               setState(BActionState state);
   virtual bool               update(float elapsed);
   virtual void               notify(DWORD eventType, BEntityID senderID, DWORD data, DWORD data2);   

   //Target.
   virtual const BSimTarget*  getTarget() const { return (&mTarget); }
   virtual void               setTarget(BSimTarget target);
   //OppID (and resulting things).
   virtual BUnitOppID         getOppID() const { return (mOppID); }
   virtual void               setOppID(BUnitOppID v);
   virtual uint               getPriority() const;

   virtual bool               isInterruptible() const { return (false); }

   //Add block pool
   DECLARE_FREELIST(BUnitActionUnhitch, 5);

   virtual bool save(BStream* pStream, int saveType) const;
   virtual bool load(BStream* pStream, int saveType);

protected:

   bool                       validateControllers() const;
   bool                       grabControllers();
   void                       releaseControllers();

   //bool                       validateRange() const;
   bool                       validateTarget() const;
   void                       playUnhitchAnimation();
   void                       updateNoAnimTimer(float elapsedTime);

   BSimTarget                 mTarget;
   BUnitOppID                 mOppID;
   float                      mNoAnimTimer;     
};
