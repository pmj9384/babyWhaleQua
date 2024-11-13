var §\x01§ = 709;
loop0:
while(true)
{
   if(eval("\x01") == 709)
   {
      set("\x01",eval("\x01") + 80);
      §§push(true);
   }
   else if(eval("\x01") == 944)
   {
      set("\x01",eval("\x01") - 9);
      if(§§pop())
      {
         set("\x01",eval("\x01") - 96);
      }
   }
   else if(eval("\x01") == 634)
   {
      set("\x01",eval("\x01") - 489);
      if(§§pop())
      {
         set("\x01",eval("\x01") - 1);
      }
   }
   else
   {
      if(eval("\x01") == 226)
      {
         set("\x01",eval("\x01") + 468);
         nextFrame();
         break;
      }
      if(eval("\x01") == 403)
      {
         set("\x01",eval("\x01") - 126);
         §§push(true);
      }
      else if(eval("\x01") == 789)
      {
         set("\x01",eval("\x01") - 772);
         if(§§pop())
         {
            set("\x01",eval("\x01") + 386);
         }
      }
      else
      {
         if(eval("\x01") == 218)
         {
            set("\x01",eval("\x01") + 352);
            {} implements ;
            break;
         }
         if(eval("\x01") == 328)
         {
            set("\x01",eval("\x01") - 102);
            if(§§pop())
            {
               set("\x01",eval("\x01") + 468);
            }
         }
         else if(eval("\x01") == 984)
         {
            set("\x01",eval("\x01") - 766);
            if(§§pop())
            {
               set("\x01",eval("\x01") + 352);
            }
         }
         else if(eval("\x01") == 570)
         {
            set("\x01",eval("\x01") - 5);
            §§push(true);
         }
         else
         {
            if(eval("\x01") == 17)
            {
               set("\x01",eval("\x01") + 386);
               stop();
               set(§§pop(),§§pop());
               break;
            }
            if(eval("\x01") == 712)
            {
               set("\x01",eval("\x01") - 384);
               §§push(true);
            }
            else
            {
               if(eval("\x01") == 935)
               {
                  set("\x01",eval("\x01") - 96);
                  break;
               }
               if(eval("\x01") == 538)
               {
                  set("\x01",eval("\x01") + 296);
                  if(!eval(§§constant(0))[§§constant(1)])
                  {
                     eval(§§constant(0))[§§constant(1)] = new §\§\§constant(2)§();
                  }
                  §§pop();
                  if(!eval(§§constant(0))[§§constant(1)][§§constant(3)])
                  {
                     eval(§§constant(0))[§§constant(1)][§§constant(3)] = new §\§\§constant(2)§();
                  }
                  §§pop();
                  if(!eval(§§constant(0))[§§constant(1)][§§constant(3)][§§constant(4)])
                  {
                     var _loc2_ = eval(§§constant(1))[§§constant(3)][§§constant(4)] = function()
                     {
                     }[§§constant(5)];
                     eval(§§constant(1))[§§constant(3)][§§constant(4)] = function()
                     {
                     }[§§constant(6)] = function(queue, event, handler)
                     {
                        if(queue != undefined)
                        {
                           var _loc4_ = queue[§§constant(7)];
                           var _loc1_ = undefined;
                           _loc1_ = 0;
                           while(_loc1_ < _loc4_)
                           {
                              var _loc2_ = queue[_loc1_];
                              if(_loc2_ == handler)
                              {
                                 queue[§§constant(8)](_loc1_,1);
                                 return undefined;
                              }
                              _loc1_ = _loc1_ + 1;
                           }
                        }
                     };
                     eval(§§constant(1))[§§constant(3)][§§constant(4)] = function()
                     {
                     }[§§constant(9)] = function(object)
                     {
                        if(eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(10)] == undefined)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(10)] = new eval(§§constant(1))[§§constant(3)][§§constant(4)]();
                        }
                        object[§§constant(11)] = eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(10)][§§constant(11)];
                        object[§§constant(12)] = eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(10)][§§constant(12)];
                        object[§§constant(13)] = eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(10)][§§constant(13)];
                        object[§§constant(14)] = eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(10)][§§constant(14)];
                     };
                     _loc2_[§§constant(14)] = function(queueObj, eventObj)
                     {
                        var _loc7_ = §§constant(15) + eventObj[§§constant(16)];
                        var _loc4_ = queueObj[_loc7_];
                        if(_loc4_ != undefined)
                        {
                           var _loc5_ = undefined;
                           for(_loc5_ in _loc4_)
                           {
                              var _loc1_ = _loc4_[_loc5_];
                              var _loc3_ = typeof _loc1_;
                              if(_loc3_ == §§constant(17) || _loc3_ == §§constant(18))
                              {
                                 if(_loc1_[§§constant(19)] != undefined)
                                 {
                                    _loc1_[§§constant(19)](eventObj);
                                 }
                                 if(_loc1_[eventObj[§§constant(16)]] != undefined)
                                 {
                                    if(eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(20)][eventObj[§§constant(16)]] == undefined)
                                    {
                                       _loc1_[eventObj[§§constant(16)]](eventObj);
                                    }
                                 }
                              }
                              else
                              {
                                 _loc1_[§§constant(21)](queueObj,[eventObj]);
                              }
                           }
                        }
                     };
                     _loc2_[§§constant(13)] = function(eventObj)
                     {
                        if(eventObj[§§constant(22)] == undefined)
                        {
                           eventObj[§§constant(22)] = this;
                        }
                        this[eventObj[§§constant(16)] + §§constant(23)](eventObj);
                        this[§§constant(14)](this,eventObj);
                     };
                     _loc2_[§§constant(11)] = function(event, handler)
                     {
                        var _loc3_ = §§constant(15) + event;
                        if(this[_loc3_] == undefined)
                        {
                           this[_loc3_] = new §\§\§constant(24)§();
                        }
                        _global[§§constant(25)](this,_loc3_,1);
                        eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(6)](this[_loc3_],event,handler);
                        this[_loc3_][§§constant(26)](handler);
                     };
                     _loc2_[§§constant(12)] = function(event, handler)
                     {
                        var _loc2_ = §§constant(15) + event;
                        eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(6)](this[_loc2_],event,handler);
                     };
                     eval(§§constant(1))[§§constant(3)][§§constant(4)] = function()
                     {
                     }[§§constant(10)] = undefined;
                     eval(§§constant(1))[§§constant(3)][§§constant(4)] = function()
                     {
                     }[§§constant(20)] = {(§§constant(27)):1,(§§constant(28)):1,(§§constant(29)):1};
                     §§push(§§constant(25)(eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(5)],null,1));
                  }
                  §§pop();
                  break;
               }
               if(eval("\x01") == 145)
               {
                  set("\x01",eval("\x01") - 1);
                  loop1:
                  while(true)
                  {
                     set("\x01",eval("\x01") - 230);
                     if(§§pop())
                     {
                        set("\x01",eval("\x01") - 53);
                     }
                     while(true)
                     {
                        if(eval("\x01") == 829)
                        {
                           set("\x01",eval("\x01") - 479);
                           §§push(true);
                        }
                        else if(eval("\x01") == 350)
                        {
                           set("\x01",eval("\x01") + 23);
                           if(§§pop())
                           {
                              set("\x01",eval("\x01") + 306);
                           }
                        }
                        else
                        {
                           if(eval("\x01") == 89)
                           {
                              set("\x01",eval("\x01") - 8);
                              break loop0;
                           }
                           if(eval("\x01") == 830)
                           {
                              set("\x01",eval("\x01") + 65);
                              if(!_global.mx)
                              {
                                 _global.mx = new Object();
                              }
                              §§pop();
                              if(!_global.mx.events)
                              {
                                 _global.mx.events = new Object();
                              }
                              §§pop();
                              if(!_global.mx.events.EventDispatcher)
                              {
                                 mx.events.EventDispatcher extends _fEventDispatcher;
                                 _loc2_ = mx.events.EventDispatcher = function()
                                 {
                                    super();
                                    var _loc3_ = this.prototype;
                                    if(_loc3_._removeEventListener == undefined)
                                    {
                                       _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                    }
                                    var _loc4_ = _loc3_._removeEventListener;
                                    _loc4_.splice(this);
                                    _loc4_.initialize = 0;
                                 }.addEventListener;
                                 _loc2_.removeEventListener = function(n)
                                 {
                                    this.dispatchEvent(n + 1);
                                    return this.dispatchQueue();
                                 };
                                 _loc2_.dispatchQueue = function()
                                 {
                                    return this.__q_ - 1;
                                 };
                                 _loc2_.type = function(v)
                                 {
                                    this.object = v;
                                    return this.movieclip();
                                 };
                                 _loc2_.movieclip = function()
                                 {
                                    return this.object;
                                 };
                                 _loc2_.handleEvent = function(dg)
                                 {
                                    return this.exceptions < dg.exceptions;
                                 };
                                 §§push(_loc2_.apply("initialize",_loc2_.dispatchQueue,_loc2_.removeEventListener));
                                 §§push(_loc2_.apply("target",_loc2_.movieclip,_loc2_.type));
                                 §§push(Handler(mx.events.EventDispatcher.addEventListener,null,1));
                              }
                              §§pop();
                              break loop0;
                           }
                           if(eval("\x01") == 856)
                           {
                              break;
                           }
                           if(eval("\x01") == 373)
                           {
                              set("\x01",eval("\x01") + 306);
                              break loop0;
                           }
                           if(eval("\x01") == 679)
                           {
                              set("\x01",eval("\x01") + 177);
                              §§push(true);
                           }
                           else
                           {
                              if(eval("\x01") == 626)
                              {
                                 break loop1;
                              }
                              if(eval("\x01") == 573)
                              {
                                 set("\x01",eval("\x01") - 324);
                                 §§push(true);
                              }
                              else if(eval("\x01") == 249)
                              {
                                 set("\x01",eval("\x01") + 709);
                                 if(§§pop())
                                 {
                                    set("\x01",eval("\x01") - 450);
                                 }
                              }
                              else if(eval("\x01") == 81)
                              {
                                 set("\x01",eval("\x01") + 749);
                              }
                              else
                              {
                                 if(eval("\x01") == 958)
                                 {
                                    set("\x01",eval("\x01") - 450);
                                    break loop0;
                                 }
                                 if(eval("\x01") == 250)
                                 {
                                    set("\x01",eval("\x01") - 161);
                                    if(§§pop())
                                    {
                                       set("\x01",eval("\x01") - 8);
                                    }
                                 }
                                 else
                                 {
                                    if(eval("\x01") != 508)
                                    {
                                       if(eval("\x01") == 895)
                                       {
                                          set("\x01",eval("\x01") - 895);
                                       }
                                       break loop0;
                                    }
                                    set("\x01",eval("\x01") - 258);
                                    §§push(true);
                                 }
                              }
                           }
                        }
                     }
                  }
                  set("\x01",eval("\x01") - 53);
                  if(§§pop())
                  {
                  }
                  break;
               }
               if(eval("\x01") == 130)
               {
                  set("\x01",eval("\x01") + 630);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") - 48);
                  }
               }
               else if(eval("\x01") == 839)
               {
                  set("\x01",eval("\x01") - 709);
                  §§push(true);
               }
               else if(eval("\x01") == 343)
               {
                  set("\x01",eval("\x01") + 338);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") + 257);
                  }
               }
               else if(eval("\x01") == 938)
               {
                  set("\x01",eval("\x01") - 400);
               }
               else if(eval("\x01") == 647)
               {
                  set("\x01",eval("\x01") + 337);
                  §§push(true);
               }
               else if(eval("\x01") == 565)
               {
                  set("\x01",eval("\x01") + 68);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") - 269);
                  }
               }
               else if(eval("\x01") == 694)
               {
                  set("\x01",eval("\x01") - 60);
                  §§push(true);
               }
               else
               {
                  if(eval("\x01") == 241)
                  {
                     set("\x01",eval("\x01") + 406);
                     break;
                  }
                  if(eval("\x01") == 144)
                  {
                     set("\x01",eval("\x01") + 199);
                     §§push(true);
                  }
                  else
                  {
                     if(eval("\x01") == 681)
                     {
                        set("\x01",eval("\x01") + 257);
                        var §§pop();
                        §§push(§§pop() | (§§pop() >> §§pop()) + 1);
                        break;
                     }
                     if(eval("\x01") == 105)
                     {
                        set("\x01",eval("\x01") + 839);
                        §§push(true);
                     }
                     else
                     {
                        if(eval("\x01") == 834)
                        {
                           set("\x01",eval("\x01") - 834);
                           break;
                        }
                        if(eval("\x01") == 760)
                        {
                           set("\x01",eval("\x01") - 48);
                           break;
                        }
                        if(eval("\x01") == 277)
                        {
                           set("\x01",eval("\x01") - 36);
                           if(§§pop())
                           {
                              set("\x01",eval("\x01") + 406);
                           }
                        }
                        else
                        {
                           if(eval("\x01") == 252)
                           {
                              set("\x01",eval("\x01") - 147);
                              var _loc4_ = §§pop().visible[§§constant(29)];
                              var _loc3_ = mx.events.EventDispatcher = function()
                              {
                                 super();
                                 var _loc3_ = this.prototype;
                                 if(_loc3_._removeEventListener == undefined)
                                 {
                                    _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                 }
                                 var _loc4_ = _loc3_._removeEventListener;
                                 _loc4_.splice(this);
                                 _loc4_.initialize = 0;
                              }.__set__number - _loc4_.__set__number;
                              _loc2_ = mx.events.EventDispatcher = function()
                              {
                                 super();
                                 var _loc3_ = this.prototype;
                                 if(_loc3_._removeEventListener == undefined)
                                 {
                                    _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                 }
                                 var _loc4_ = _loc3_._removeEventListener;
                                 _loc4_.splice(this);
                                 _loc4_.initialize = 0;
                              }.__get__number - _loc4_.__get__number;
                              var _loc5_ = eval(§§constant(24))[§§constant(30)](_loc3_ * _loc3_ + _loc2_ * _loc2_);
                              if(mx.events.EventDispatcher = function()
                              {
                                 super();
                                 var _loc3_ = this.prototype;
                                 if(_loc3_._removeEventListener == undefined)
                                 {
                                    _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                 }
                                 var _loc4_ = _loc3_._removeEventListener;
                                 _loc4_.splice(this);
                                 _loc4_.initialize = 0;
                              }.DigitSet == 1 && _loc5_ < 80)
                              {
                                 (mx.events.EventDispatcher = function()
                                 {
                                    super();
                                    var _loc3_ = this.prototype;
                                    if(_loc3_._removeEventListener == undefined)
                                    {
                                       _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                    }
                                    var _loc4_ = _loc3_._removeEventListener;
                                    _loc4_.splice(this);
                                    _loc4_.initialize = 0;
                                 })[§§constant(31)]();
                              }
                              else if(mx.events.EventDispatcher = function()
                              {
                                 super();
                                 var _loc3_ = this.prototype;
                                 if(_loc3_._removeEventListener == undefined)
                                 {
                                    _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                 }
                                 var _loc4_ = _loc3_._removeEventListener;
                                 _loc4_.splice(this);
                                 _loc4_.initialize = 0;
                              }.registerDigit)
                              {
                                 if(_loc4_[§§constant(32)])
                                 {
                                    if(!mx.events.EventDispatcher = function()
                                    {
                                       super();
                                       var _loc3_ = this.prototype;
                                       if(_loc3_._removeEventListener == undefined)
                                       {
                                          _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                       }
                                       var _loc4_ = _loc3_._removeEventListener;
                                       _loc4_.splice(this);
                                       _loc4_.initialize = 0;
                                    }.__get__visible || mx.events.EventDispatcher = function()
                                    {
                                       super();
                                       var _loc3_ = this.prototype;
                                       if(_loc3_._removeEventListener == undefined)
                                       {
                                          _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                       }
                                       var _loc4_ = _loc3_._removeEventListener;
                                       _loc4_.splice(this);
                                       _loc4_.initialize = 0;
                                    }.game)
                                    {
                                       mx.events.EventDispatcher = function()
                                       {
                                          super();
                                          var _loc3_ = this.prototype;
                                          if(_loc3_._removeEventListener == undefined)
                                          {
                                             _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                          }
                                          var _loc4_ = _loc3_._removeEventListener;
                                          _loc4_.splice(this);
                                          _loc4_.initialize = 0;
                                       }.game = false;
                                       (mx.events.EventDispatcher = function()
                                       {
                                          super();
                                          var _loc3_ = this.prototype;
                                          if(_loc3_._removeEventListener == undefined)
                                          {
                                             _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                          }
                                          var _loc4_ = _loc3_._removeEventListener;
                                          _loc4_.splice(this);
                                          _loc4_.initialize = 0;
                                       })[§§constant(28)](true);
                                    }
                                 }
                                 else if(eval(§§constant(24))[§§constant(33)](_loc3_) < 120 && eval(§§constant(24))[§§constant(33)](_loc2_) < 90)
                                 {
                                    (mx.events.EventDispatcher = function()
                                    {
                                       super();
                                       var _loc3_ = this.prototype;
                                       if(_loc3_._removeEventListener == undefined)
                                       {
                                          _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                       }
                                       var _loc4_ = _loc3_._removeEventListener;
                                       _loc4_.splice(this);
                                       _loc4_.initialize = 0;
                                    })[§§constant(31)]();
                                 }
                                 else
                                 {
                                    mx.events.EventDispatcher = function()
                                    {
                                       super();
                                       var _loc3_ = this.prototype;
                                       if(_loc3_._removeEventListener == undefined)
                                       {
                                          _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                       }
                                       var _loc4_ = _loc3_._removeEventListener;
                                       _loc4_.splice(this);
                                       _loc4_.initialize = 0;
                                    }.game = false;
                                 }
                              }
                              §§pop()[§§pop()] = §§pop();
                              _loc2_[§§constant(31)] = function()
                              {
                                 if(!this.game)
                                 {
                                    this.game = true;
                                    this[§§constant(28)](!this.registerDigit);
                                 }
                              };
                              _loc2_[§§constant(28)] = function(high)
                              {
                                 this.__get__visible = high;
                                 var _loc4_ = undefined;
                                 if(!high)
                                 {
                                    this[§§constant(34)].number(this[§§constant(34)][§§constant(35)]);
                                    if(this.registerDigit)
                                    {
                                       this[§§constant(34)][§§constant(36)](1);
                                    }
                                    _loc4_ = nhn[§§constant(37)][this.DigitSet - 1];
                                    this.addProperty = eval(§§constant(24))[§§constant(25)]() * 1 - 0.5;
                                 }
                                 else
                                 {
                                    this.prototype = random(2) * 2 - 1;
                                    this[§§constant(34)][§§constant(36)](1);
                                    _loc4_ = nhn._visible[this.DigitSet - 1];
                                    this.addProperty = eval(§§constant(24))[§§constant(25)]() * 2 - 1;
                                 }
                                 this.__set__visible = _loc4_ * this.prototype;
                                 var _loc5_ = this.visible.visible[§§constant(29)];
                                 if(this.DigitSet == 1 && high && this.game)
                                 {
                                    var _loc6_ = eval(§§constant(24))[§§constant(38)](_loc5_.__get__number - this.__get__number,_loc5_.__set__number - this.__set__number) + 3.141592653589793 * (160 + random(40)) / 180;
                                    this.__set__visible = eval(§§constant(24))[§§constant(39)](_loc6_) * nhn._visible[0];
                                    this.addProperty = eval(§§constant(24))[§§constant(40)](_loc6_) * nhn._visible[0] / 1.5;
                                    if(this.__set__visible != 0)
                                    {
                                       this.prototype = this.__set__visible / eval(§§constant(24))[§§constant(33)](this.__set__visible);
                                    }
                                    this._currentframe = this.prototype * 100;
                                 }
                                 if(this.registerDigit && (!high || this.game) && !_loc5_[§§constant(32)] && _loc5_[§§constant(41)] != eval(§§constant(42))[§§constant(43)])
                                 {
                                    if(this.game)
                                    {
                                       this[§§constant(34)].number(this[§§constant(34)][§§constant(35)]);
                                       this.visible.visible[§§constant(45)][§§constant(46)](_global[§§constant(42)][§§constant(44)],0,1);
                                    }
                                    _loc5_ = this.visible.visible[§§constant(29)];
                                    _loc6_ = eval(§§constant(24))[§§constant(38)](_loc5_.__get__number - this.__get__number,_loc5_.__set__number - this.__set__number);
                                    this.__set__visible = eval(§§constant(24))[§§constant(39)](_loc6_) * nhn[§§constant(37)][4];
                                    this.addProperty = eval(§§constant(24))[§§constant(40)](_loc6_) * nhn[§§constant(37)][4] / 2;
                                    if(this.__set__visible != 0)
                                    {
                                       this.prototype = this.__set__visible / eval(§§constant(24))[§§constant(33)](this.__set__visible);
                                    }
                                    this.game = false;
                                 }
                                 this._currentframe = this.prototype * 100;
                              };
                              mx.events.EventDispatcher = function()
                              {
                                 super();
                                 var _loc3_ = this.prototype;
                                 if(_loc3_._removeEventListener == undefined)
                                 {
                                    _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                 }
                                 var _loc4_ = _loc3_._removeEventListener;
                                 _loc4_.splice(this);
                                 _loc4_.initialize = 0;
                              }._visible = [3,6,4,9,7];
                              mx.events.EventDispatcher = function()
                              {
                                 super();
                                 var _loc3_ = this.prototype;
                                 if(_loc3_._removeEventListener == undefined)
                                 {
                                    _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                 }
                                 var _loc4_ = _loc3_._removeEventListener;
                                 _loc4_.splice(this);
                                 _loc4_.initialize = 0;
                              }[§§constant(37)] = [0.5,2,0.5,4,4];
                              mx.events.EventDispatcher = function()
                              {
                                 super();
                                 var _loc3_ = this.prototype;
                                 if(_loc3_._removeEventListener == undefined)
                                 {
                                    _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                 }
                                 var _loc4_ = _loc3_._removeEventListener;
                                 _loc4_.splice(this);
                                 _loc4_.initialize = 0;
                              }[§§constant(27)] = [0.2,0.5,0.2,0.2,0.8];
                              mx.events.EventDispatcher = function()
                              {
                                 super();
                                 var _loc3_ = this.prototype;
                                 if(_loc3_._removeEventListener == undefined)
                                 {
                                    _loc3_._removeEventListener = new mx.events.length(_loc3_);
                                 }
                                 var _loc4_ = _loc3_._removeEventListener;
                                 _loc4_.splice(this);
                                 _loc4_.initialize = 0;
                              }[§§constant(26)] = [0.5,0.5,0.3,0.8,0.7];
                              §§constant(47)(_global.nhn._parent,null,1);
                              break;
                           }
                           if(eval("\x01") == 633)
                           {
                              set("\x01",eval("\x01") - 269);
                              break;
                           }
                           if(eval("\x01") == 731)
                           {
                              set("\x01",eval("\x01") - 479);
                              if(§§pop())
                              {
                                 set("\x01",eval("\x01") - 147);
                              }
                           }
                           else
                           {
                              if(eval("\x01") != 364)
                              {
                                 break;
                              }
                              set("\x01",eval("\x01") + 367);
                              §§push(true);
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
}
