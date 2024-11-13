var §\x01§ = 833;
while(true)
{
   if(eval("\x01") == 833)
   {
      set("\x01",eval("\x01") - 398);
      §§push(true);
   }
   else
   {
      if(eval("\x01") != 457)
      {
         if(eval("\x01") == 316)
         {
            set("\x01",eval("\x01") - 69);
         }
         else
         {
            if(eval("\x01") == 274)
            {
               set("\x01",eval("\x01") + 42);
               if(§§pop())
               {
                  set("\x01",eval("\x01") - 69);
               }
               continue;
            }
            if(eval("\x01") == 247)
            {
               set("\x01",eval("\x01") + 152);
               continue;
            }
            if(eval("\x01") == 364)
            {
               set("\x01",eval("\x01") + 153);
            }
            else
            {
               if(eval("\x01") == 435)
               {
                  set("\x01",eval("\x01") - 11);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") + 33);
                  }
                  continue;
               }
               if(eval("\x01") == 513)
               {
                  set("\x01",eval("\x01") - 239);
                  §§push(true);
                  continue;
               }
               if(eval("\x01") == 399)
               {
                  set("\x01",eval("\x01") - 25);
                  if(!_global.nhn)
                  {
                     _global.nhn = new Object();
                  }
                  §§pop();
                  if(!_global.nhn.game)
                  {
                     _global.nhn.game = new Object();
                  }
                  §§pop();
                  if(!_global.nhn.game.Timer)
                  {
                     var _loc2_ = nhn.game.Timer = function()
                     {
                        this.remain = 0;
                        this.started = false;
                        this.paused = false;
                        mx.events.EventDispatcher.initialize(this);
                     }.prototype;
                     _loc2_.startTimer = function(tot, up)
                     {
                        this.total = tot;
                        this.remain = this.total;
                        this.update = up;
                        this.lastTime = getTimer();
                        this.count = Math.ceil(this.total / this.update);
                        if(this.started)
                        {
                           this.clearTimer();
                        }
                        this.started = true;
                        this.paused = false;
                        this.intervalID = setInterval(this,"updateTimer",this.update);
                        this.dispatchEvent({type:"update",value:this.remain});
                     };
                     _loc2_.clearTimer = function()
                     {
                        clearInterval(this.intervalID);
                        this.started = false;
                        this.dispatchEvent({type:"clear",value:this.remain});
                     };
                     _loc2_.pause = function()
                     {
                        if(this.started && !this.paused)
                        {
                           this.paused = true;
                           clearInterval(this.intervalID);
                           this.dispatchEvent({type:"pause",value:this.remain});
                        }
                     };
                     _loc2_.unpause = function()
                     {
                        if(this.started && this.paused)
                        {
                           this.paused = false;
                           this.lastTime = getTimer() - this.update;
                           this.updateTimer();
                           this.intervalID = setInterval(this,"updateTimer",this.update);
                           this.dispatchEvent({type:"unpause",value:this.remain});
                        }
                     };
                     _loc2_.getPaused = function()
                     {
                        return this.paused;
                     };
                     _loc2_.addPauseListener = function(obj)
                     {
                        this.addEventListener("pause",obj);
                        this.addEventListener("unpause",obj);
                     };
                     _loc2_.removePauseListener = function(obj)
                     {
                        this.removeEventListener("pause",obj);
                        this.removeEventListener("unpause",obj);
                     };
                     _loc2_.getRemainTime = function()
                     {
                        return this.remain + (this.lastTime - getTimer());
                     };
                     _loc2_.getPassTime = function()
                     {
                        return this.total - (this.remain + (this.lastTime - getTimer()));
                     };
                     _loc2_.getTimer = function()
                     {
                        return this.getPassTime();
                     };
                     _loc2_.updateTimer = function()
                     {
                        var _loc2_ = getTimer();
                        var _loc3_ = this.remain;
                        this.remain += this.lastTime - _loc2_;
                        this.error = _loc3_ - this.remain - this.update;
                        this.lastTime = _loc2_;
                        this.dispatchEvent({type:"update",value:this.remain});
                        if(--this.count == 0)
                        {
                           this.clearTimer();
                           this.dispatchEvent({type:"end",value:this.remain});
                        }
                     };
                     _loc2_.setDelay = function()
                     {
                        var _loc3_ = arguments;
                        var obj = _loc3_[0];
                        var fnc = _loc3_[1];
                        var delay = _loc3_[2];
                        if(typeof obj == "function" && typeof fnc == "number")
                        {
                           delay = fnc;
                           fnc = obj;
                           obj = null;
                           var _loc6_ = 2;
                        }
                        else
                        {
                           if(!(obj instanceof Object && typeof (fnc = obj[fnc]) == "function" && typeof delay == "number"))
                           {
                              return false;
                           }
                           _loc6_ = 3;
                        }
                        _loc3_.splice(0,_loc6_);
                        var startTime = this.getPassTime();
                        var _loc4_ = {startTime:startTime,delay:delay,timer:this,args:_loc3_,fnc:fnc,obj:obj,update:function(e)
                        {
                           var _loc2_ = e.target.getPassTime();
                           if(_loc2_ - this.startTime > this.delay)
                           {
                              this.fnc.apply(this.obj,this.args);
                              this.timer.removeEventListener("update",this);
                           }
                        }};
                        this.addEventListener("update",_loc4_);
                        return _loc4_;
                     };
                     nhn.game.Timer = function()
                     {
                        this.remain = 0;
                        this.started = false;
                        this.paused = false;
                        mx.events.EventDispatcher.initialize(this);
                     }.setDelayCall = function()
                     {
                        var _loc2_ = arguments;
                        var obj = _loc2_[0];
                        var fnc = _loc2_[1];
                        var _loc3_ = _loc2_[2];
                        if(typeof obj == "function" && typeof fnc == "number")
                        {
                           _loc3_ = fnc;
                           fnc = obj;
                           obj = null;
                           var _loc4_ = 2;
                        }
                        else
                        {
                           if(!(typeof (fnc = obj[fnc]) == "function" && typeof _loc3_ == "number"))
                           {
                              return false;
                           }
                           _loc4_ = 3;
                        }
                        _loc2_.splice(0,_loc4_);
                        var _loc5_ = function(array)
                        {
                           fnc.apply(obj,array);
                           clearInterval(id);
                        };
                        var id = setInterval(_loc5_,_loc3_,_loc2_);
                        return id;
                     };
                     _loc2_.error = 0;
                     §§push(ASSetPropFlags(nhn.game.Timer.prototype,null,1));
                  }
                  §§pop();
                  break;
               }
               if(eval("\x01") != 448)
               {
                  if(eval("\x01") == 424)
                  {
                     set("\x01",eval("\x01") + 33);
                     §§push(mblength(§§pop()));
                     break;
                  }
                  if(eval("\x01") == 374)
                  {
                     set("\x01",eval("\x01") - 374);
                     break;
                  }
                  if(eval("\x01") == 433)
                  {
                     set("\x01",eval("\x01") - 69);
                     if(§§pop())
                     {
                        set("\x01",eval("\x01") + 153);
                     }
                  }
                  else if(eval("\x01") == 254)
                  {
                     set("\x01",eval("\x01") + 194);
                     if(§§pop())
                     {
                        set("\x01",eval("\x01") + 65);
                     }
                  }
                  else
                  {
                     if(eval("\x01") != 517)
                     {
                        break;
                     }
                     set("\x01",eval("\x01") - 263);
                     §§push(true);
                  }
                  continue;
               }
               set("\x01",eval("\x01") + 65);
            }
         }
         nextFrame();
         with(§§pop().substr(§§pop(),§§pop() or §§pop()))
         {
         }
         break;
      }
      set("\x01",eval("\x01") - 24);
      §§push(true);
   }
}
