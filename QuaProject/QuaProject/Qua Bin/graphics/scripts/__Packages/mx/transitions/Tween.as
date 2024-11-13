var §\x01§ = 514;
while(true)
{
   if(eval("\x01") == 514)
   {
      set("\x01",eval("\x01") + 72);
      §§push(true);
   }
   else if(eval("\x01") == 571)
   {
      set("\x01",eval("\x01") + 91);
      §§push(true);
   }
   else
   {
      if(eval("\x01") == 720)
      {
         set("\x01",eval("\x01") + 28);
         break;
      }
      if(eval("\x01") == 159)
      {
         set("\x01",eval("\x01") + 127);
         if(§§pop())
         {
            set("\x01",eval("\x01") + 285);
         }
      }
      else if(eval("\x01") == 918)
      {
         set("\x01",eval("\x01") - 759);
         §§push(true);
      }
      else
      {
         if(eval("\x01") == 339)
         {
            set("\x01",eval("\x01") + 189);
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
               var _loc2_ = eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
               {
                  eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                  if(!arguments[§§constant(7)])
                  {
                     return undefined;
                  }
                  this[§§constant(8)] = obj;
                  this[§§constant(9)] = prop;
                  this[§§constant(10)] = begin;
                  this[§§constant(11)](begin);
                  this[§§constant(12)](duration);
                  this[§§constant(13)] = useSeconds;
                  if(func)
                  {
                     this[§§constant(14)] = func;
                  }
                  this[§§constant(15)](finish);
                  this[§§constant(16)] = [];
                  this[§§constant(17)](this);
                  this[§§constant(18)]();
               }[§§constant(19)];
               _loc2_[§§constant(20)] = function(t)
               {
                  this[§§constant(21)] = this[§§constant(22)];
                  if(t > this[§§constant(23)]())
                  {
                     if(this[§§constant(24)])
                     {
                        this[§§constant(26)](t - this[§§constant(25)]);
                        this[§§constant(27)]();
                        this[§§constant(29)](§§constant(28),this);
                     }
                     else
                     {
                        if(this[§§constant(13)])
                        {
                           this[§§constant(22)] = this[§§constant(25)];
                           this[§§constant(27)]();
                        }
                        this[§§constant(30)]();
                        this[§§constant(29)](§§constant(31),this);
                     }
                  }
                  else if(t < 0)
                  {
                     this[§§constant(26)]();
                     this[§§constant(27)]();
                  }
                  else
                  {
                     this[§§constant(22)] = t;
                     this[§§constant(27)]();
                  }
                  return this[§§constant(32)]();
               };
               _loc2_[§§constant(32)] = function()
               {
                  return this[§§constant(22)];
               };
               _loc2_[§§constant(12)] = function(d)
               {
                  this[§§constant(25)] = !(d == null || d <= 0) ? d : _global[§§constant(33)];
                  return this[§§constant(23)]();
               };
               _loc2_[§§constant(23)] = function()
               {
                  return this[§§constant(25)];
               };
               _loc2_[§§constant(34)] = function(fps)
               {
                  var _loc2_ = this[§§constant(35)];
                  this[§§constant(36)]();
                  this[§§constant(37)] = fps;
                  if(_loc2_)
                  {
                     this[§§constant(38)]();
                  }
                  return this[§§constant(39)]();
               };
               _loc2_[§§constant(39)] = function()
               {
                  return this[§§constant(37)];
               };
               _loc2_[§§constant(11)] = function(p)
               {
                  this[§§constant(40)](p);
                  return this[§§constant(41)]();
               };
               _loc2_[§§constant(40)] = function(p)
               {
                  this[§§constant(42)] = this[§§constant(43)];
                  this[§§constant(8)][this[§§constant(9)]] = this[§§constant(43)] = p;
                  this[§§constant(29)](§§constant(44),this,this[§§constant(43)]);
                  §§constant(45)();
               };
               _loc2_[§§constant(41)] = function()
               {
                  return this[§§constant(46)]();
               };
               _loc2_[§§constant(46)] = function(t)
               {
                  if(t == undefined)
                  {
                     t = this[§§constant(22)];
                  }
                  return this[§§constant(14)](t,this[§§constant(10)],this[§§constant(47)],this[§§constant(25)]);
               };
               _loc2_[§§constant(15)] = function(f)
               {
                  this[§§constant(47)] = f - this[§§constant(10)];
                  return this[§§constant(48)]();
               };
               _loc2_[§§constant(48)] = function()
               {
                  return this[§§constant(10)] + this[§§constant(47)];
               };
               _loc2_[§§constant(49)] = function(finish, duration)
               {
                  this[§§constant(10)] = this[§§constant(50)];
                  this[§§constant(15)](finish);
                  if(duration != undefined)
                  {
                     this[§§constant(12)](duration);
                  }
                  this[§§constant(18)]();
               };
               _loc2_[§§constant(51)] = function()
               {
                  this[§§constant(49)](this[§§constant(10)],this[§§constant(32)]());
               };
               _loc2_[§§constant(38)] = function()
               {
                  if(this[§§constant(37)] == undefined)
                  {
                     _global[§§constant(52)][§§constant(17)](this);
                  }
                  else
                  {
                     this[§§constant(53)] = §§constant(55)(this,§§constant(54),1000 / this[§§constant(37)]);
                  }
                  this[§§constant(35)] = true;
               };
               _loc2_[§§constant(36)] = function()
               {
                  if(this[§§constant(37)] == undefined)
                  {
                     _global[§§constant(52)][§§constant(56)](this);
                  }
                  else
                  {
                     §§constant(57)(this[§§constant(53)]);
                  }
                  this[§§constant(35)] = false;
               };
               _loc2_[§§constant(18)] = function()
               {
                  this[§§constant(26)]();
                  this[§§constant(38)]();
                  this[§§constant(29)](§§constant(58),this);
               };
               _loc2_[§§constant(30)] = function()
               {
                  this[§§constant(36)]();
                  this[§§constant(29)](§§constant(59),this);
               };
               _loc2_[§§constant(60)] = function()
               {
                  this[§§constant(61)]();
                  this[§§constant(38)]();
                  this[§§constant(29)](§§constant(62),this);
               };
               _loc2_[§§constant(26)] = function(t)
               {
                  this[§§constant(22)] = t != undefined ? t : 0;
                  this[§§constant(61)]();
                  this[§§constant(27)]();
               };
               _loc2_[§§constant(63)] = function()
               {
                  this[§§constant(20)](this[§§constant(25)]);
                  this[§§constant(61)]();
               };
               _loc2_[§§constant(64)] = function()
               {
                  if(this[§§constant(13)])
                  {
                     this[§§constant(20)]((getTimer() - this[§§constant(65)]) / 1000);
                  }
                  else
                  {
                     this[§§constant(20)](this[§§constant(22)] + 1);
                  }
               };
               _loc2_[§§constant(54)] = function()
               {
                  this[§§constant(64)]();
               };
               _loc2_[§§constant(66)] = function()
               {
                  if(!this[§§constant(13)])
                  {
                     this[§§constant(20)](this[§§constant(22)] - 1);
                  }
               };
               _loc2_[§§constant(67)] = function()
               {
                  return §§constant(68);
               };
               _loc2_[§§constant(61)] = function()
               {
                  if(this[§§constant(13)])
                  {
                     this[§§constant(65)] = getTimer() - this[§§constant(22)] * 1000;
                  }
               };
               _loc2_[§§constant(27)] = function()
               {
                  this[§§constant(11)](this[§§constant(46)](this[§§constant(22)]));
               };
               eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
               {
                  eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                  if(!arguments[§§constant(7)])
                  {
                     return undefined;
                  }
                  this[§§constant(8)] = obj;
                  this[§§constant(9)] = prop;
                  this[§§constant(10)] = begin;
                  this[§§constant(11)](begin);
                  this[§§constant(12)](duration);
                  this[§§constant(13)] = useSeconds;
                  if(func)
                  {
                     this[§§constant(14)] = func;
                  }
                  this[§§constant(15)](finish);
                  this[§§constant(16)] = [];
                  this[§§constant(17)](this);
                  this[§§constant(18)]();
               }[§§constant(69)] = §§constant(70);
               eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
               {
                  eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                  if(!arguments[§§constant(7)])
                  {
                     return undefined;
                  }
                  this[§§constant(8)] = obj;
                  this[§§constant(9)] = prop;
                  this[§§constant(10)] = begin;
                  this[§§constant(11)](begin);
                  this[§§constant(12)](duration);
                  this[§§constant(13)] = useSeconds;
                  if(func)
                  {
                     this[§§constant(14)] = func;
                  }
                  this[§§constant(15)](finish);
                  this[§§constant(16)] = [];
                  this[§§constant(17)](this);
                  this[§§constant(18)]();
               }[§§constant(71)] = eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
               eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
               {
                  eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                  if(!arguments[§§constant(7)])
                  {
                     return undefined;
                  }
                  this[§§constant(8)] = obj;
                  this[§§constant(9)] = prop;
                  this[§§constant(10)] = begin;
                  this[§§constant(11)](begin);
                  this[§§constant(12)](duration);
                  this[§§constant(13)] = useSeconds;
                  if(func)
                  {
                     this[§§constant(14)] = func;
                  }
                  this[§§constant(15)](finish);
                  this[§§constant(16)] = [];
                  this[§§constant(17)](this);
                  this[§§constant(18)]();
               }[§§constant(72)] = eval(§§constant(1))[§§constant(3)][§§constant(73)][§§constant(74)](eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(19)],true);
               _loc2_[§§constant(14)] = function(t, b, c, d)
               {
                  return c * t / d + b;
               };
               §§push(_loc2_[§§constant(76)](§§constant(75),_loc2_[§§constant(39)],_loc2_[§§constant(34)]));
               §§push(_loc2_[§§constant(76)](§§constant(77),_loc2_[§§constant(23)],_loc2_[§§constant(12)]));
               §§push(_loc2_[§§constant(76)](§§constant(78),_loc2_[§§constant(48)],_loc2_[§§constant(15)]));
               §§push(_loc2_[§§constant(76)](§§constant(50),_loc2_[§§constant(41)],_loc2_[§§constant(11)]));
               §§push(_loc2_[§§constant(76)](§§constant(79),_loc2_[§§constant(32)],_loc2_[§§constant(20)]));
               §§push(§§constant(80)(eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(19)],null,1));
            }
            §§pop();
            break;
         }
         if(eval("\x01") == 748)
         {
            set("\x01",eval("\x01") - 405);
            §§push(true);
         }
         else if(eval("\x01") == 781)
         {
            set("\x01",eval("\x01") - 182);
            §§push(true);
         }
         else if(eval("\x01") == 586)
         {
            set("\x01",eval("\x01") + 134);
            if(§§pop())
            {
               set("\x01",eval("\x01") + 28);
            }
         }
         else if(eval("\x01") == 337)
         {
            set("\x01",eval("\x01") + 572);
            §§push(true);
         }
         else
         {
            if(eval("\x01") == 349)
            {
               set("\x01",eval("\x01") + 569);
               break;
            }
            if(eval("\x01") == 239)
            {
               set("\x01",eval("\x01") + 521);
               break;
            }
            if(eval("\x01") == 343)
            {
               set("\x01",eval("\x01") - 104);
               if(§§pop())
               {
                  set("\x01",eval("\x01") + 521);
               }
            }
            else if(eval("\x01") == 599)
            {
               set("\x01",eval("\x01") - 290);
               if(§§pop())
               {
                  set("\x01",eval("\x01") + 28);
               }
            }
            else if(eval("\x01") == 760)
            {
               set("\x01",eval("\x01") - 670);
               §§push(true);
            }
            else if(eval("\x01") == 90)
            {
               set("\x01",eval("\x01") + 1);
               if(§§pop())
               {
                  set("\x01",eval("\x01") + 690);
               }
            }
            else
            {
               if(eval("\x01") == 91)
               {
                  set("\x01",eval("\x01") + 690);
                  §§enumerate(§§pop()[§§pop()]);
                  break;
               }
               if(eval("\x01") == 309)
               {
                  set("\x01",eval("\x01") + 28);
                  break;
               }
               if(eval("\x01") == 286)
               {
                  set("\x01",eval("\x01") + 285);
                  nextFrame();
                  toggleHighQuality();
                  nextFrame();
                  nextFrame();
                  toggleHighQuality();
                  §§pop()[§§pop()] = §§pop() - §§pop()[§§pop() + §§pop()];
                  return (eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                  {
                     eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                     if(!arguments[§§constant(7)])
                     {
                        return undefined;
                     }
                     this[§§constant(8)] = obj;
                     this[§§constant(9)] = prop;
                     this[§§constant(10)] = begin;
                     this[§§constant(11)](begin);
                     this[§§constant(12)](duration);
                     this[§§constant(13)] = useSeconds;
                     if(func)
                     {
                        this[§§constant(14)] = func;
                     }
                     this[§§constant(15)](finish);
                     this[§§constant(16)] = [];
                     this[§§constant(17)](this);
                     this[§§constant(18)]();
                  })[§§constant(48)]();
               }
               if(eval("\x01") == 909)
               {
                  set("\x01",eval("\x01") - 560);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") + 569);
                  }
               }
               else if(eval("\x01") == 662)
               {
                  set("\x01",eval("\x01") + 63);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") + 46);
                  }
               }
               else
               {
                  if(eval("\x01") == 725)
                  {
                     set("\x01",eval("\x01") + 46);
                     §§pop();
                     eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                        if(!arguments[§§constant(7)])
                        {
                           return undefined;
                        }
                        this[§§constant(8)] = obj;
                        this[§§constant(9)] = prop;
                        this[§§constant(10)] = begin;
                        this[§§constant(11)](begin);
                        this[§§constant(12)](duration);
                        this[§§constant(13)] = useSeconds;
                        if(func)
                        {
                           this[§§constant(14)] = func;
                        }
                        this[§§constant(15)](finish);
                        this[§§constant(16)] = [];
                        this[§§constant(17)](this);
                        this[§§constant(18)]();
                     }._listeners = looping.__get__FPS(_loc6_) * mx.addListener[0];
                     eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                        if(!arguments[§§constant(7)])
                        {
                           return undefined;
                        }
                        this[§§constant(8)] = obj;
                        this[§§constant(9)] = prop;
                        this[§§constant(10)] = begin;
                        this[§§constant(11)](begin);
                        this[§§constant(12)](duration);
                        this[§§constant(13)] = useSeconds;
                        if(func)
                        {
                           this[§§constant(14)] = func;
                        }
                        this[§§constant(15)](finish);
                        this[§§constant(16)] = [];
                        this[§§constant(17)](this);
                        this[§§constant(18)]();
                     }.prevTime = looping.setPosition(_loc6_) * mx.addListener[0] / 1.5;
                     if(eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                        if(!arguments[§§constant(7)])
                        {
                           return undefined;
                        }
                        this[§§constant(8)] = obj;
                        this[§§constant(9)] = prop;
                        this[§§constant(10)] = begin;
                        this[§§constant(11)](begin);
                        this[§§constant(12)](duration);
                        this[§§constant(13)] = useSeconds;
                        if(func)
                        {
                           this[§§constant(14)] = func;
                        }
                        this[§§constant(15)](finish);
                        this[§§constant(16)] = [];
                        this[§§constant(17)](this);
                        this[§§constant(18)]();
                     }._listeners != 0)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                           if(!arguments[§§constant(7)])
                           {
                              return undefined;
                           }
                           this[§§constant(8)] = obj;
                           this[§§constant(9)] = prop;
                           this[§§constant(10)] = begin;
                           this[§§constant(11)](begin);
                           this[§§constant(12)](duration);
                           this[§§constant(13)] = useSeconds;
                           if(func)
                           {
                              this[§§constant(14)] = func;
                           }
                           this[§§constant(15)](finish);
                           this[§§constant(16)] = [];
                           this[§§constant(17)](this);
                           this[§§constant(18)]();
                        }.__set__position = eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                           if(!arguments[§§constant(7)])
                           {
                              return undefined;
                           }
                           this[§§constant(8)] = obj;
                           this[§§constant(9)] = prop;
                           this[§§constant(10)] = begin;
                           this[§§constant(11)](begin);
                           this[§§constant(12)](duration);
                           this[§§constant(13)] = useSeconds;
                           if(func)
                           {
                              this[§§constant(14)] = func;
                           }
                           this[§§constant(15)](finish);
                           this[§§constant(16)] = [];
                           this[§§constant(17)](this);
                           this[§§constant(18)]();
                        }._listeners / looping.Infinity(eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                           if(!arguments[§§constant(7)])
                           {
                              return undefined;
                           }
                           this[§§constant(8)] = obj;
                           this[§§constant(9)] = prop;
                           this[§§constant(10)] = begin;
                           this[§§constant(11)](begin);
                           this[§§constant(12)](duration);
                           this[§§constant(13)] = useSeconds;
                           if(func)
                           {
                              this[§§constant(14)] = func;
                           }
                           this[§§constant(15)](finish);
                           this[§§constant(16)] = [];
                           this[§§constant(17)](this);
                           this[§§constant(18)]();
                        }._listeners);
                     }
                     eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                        if(!arguments[§§constant(7)])
                        {
                           return undefined;
                        }
                        this[§§constant(8)] = obj;
                        this[§§constant(9)] = prop;
                        this[§§constant(10)] = begin;
                        this[§§constant(11)](begin);
                        this[§§constant(12)](duration);
                        this[§§constant(13)] = useSeconds;
                        if(func)
                        {
                           this[§§constant(14)] = func;
                        }
                        this[§§constant(15)](finish);
                        this[§§constant(16)] = [];
                        this[§§constant(17)](this);
                        this[§§constant(18)]();
                     }.__set__finish = eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                        if(!arguments[§§constant(7)])
                        {
                           return undefined;
                        }
                        this[§§constant(8)] = obj;
                        this[§§constant(9)] = prop;
                        this[§§constant(10)] = begin;
                        this[§§constant(11)](begin);
                        this[§§constant(12)](duration);
                        this[§§constant(13)] = useSeconds;
                        if(func)
                        {
                           this[§§constant(14)] = func;
                        }
                        this[§§constant(15)](finish);
                        this[§§constant(16)] = [];
                        this[§§constant(17)](this);
                        this[§§constant(18)]();
                     }.__set__position * 100;
                     if(eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                        if(!arguments[§§constant(7)])
                        {
                           return undefined;
                        }
                        this[§§constant(8)] = obj;
                        this[§§constant(9)] = prop;
                        this[§§constant(10)] = begin;
                        this[§§constant(11)](begin);
                        this[§§constant(12)](duration);
                        this[§§constant(13)] = useSeconds;
                        if(func)
                        {
                           this[§§constant(14)] = func;
                        }
                        this[§§constant(15)](finish);
                        this[§§constant(16)] = [];
                        this[§§constant(17)](this);
                        this[§§constant(18)]();
                     }.obj && (!_loc3_ || eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                        if(!arguments[§§constant(7)])
                        {
                           return undefined;
                        }
                        this[§§constant(8)] = obj;
                        this[§§constant(9)] = prop;
                        this[§§constant(10)] = begin;
                        this[§§constant(11)](begin);
                        this[§§constant(12)](duration);
                        this[§§constant(13)] = useSeconds;
                        if(func)
                        {
                           this[§§constant(14)] = func;
                        }
                        this[§§constant(15)](finish);
                        this[§§constant(16)] = [];
                        this[§§constant(17)](this);
                        this[§§constant(18)]();
                     }.transitions) && !_loc5_.__get__time && _loc5_.__get__position != prevPos._pos)
                     {
                        if(eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                           if(!arguments[§§constant(7)])
                           {
                              return undefined;
                           }
                           this[§§constant(8)] = obj;
                           this[§§constant(9)] = prop;
                           this[§§constant(10)] = begin;
                           this[§§constant(11)](begin);
                           this[§§constant(12)](duration);
                           this[§§constant(13)] = useSeconds;
                           if(func)
                           {
                              this[§§constant(14)] = func;
                           }
                           this[§§constant(15)](finish);
                           this[§§constant(16)] = [];
                           this[§§constant(17)](this);
                           this[§§constant(18)]();
                        }.transitions)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                           {
                              eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                              if(!arguments[§§constant(7)])
                              {
                                 return undefined;
                              }
                              this[§§constant(8)] = obj;
                              this[§§constant(9)] = prop;
                              this[§§constant(10)] = begin;
                              this[§§constant(11)](begin);
                              this[§§constant(12)](duration);
                              this[§§constant(13)] = useSeconds;
                              if(func)
                              {
                                 this[§§constant(14)] = func;
                              }
                              this[§§constant(15)](finish);
                              this[§§constant(16)] = [];
                              this[§§constant(17)](this);
                              this[§§constant(18)]();
                           }.__set__FPS.prop(eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                           {
                              eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                              if(!arguments[§§constant(7)])
                              {
                                 return undefined;
                              }
                              this[§§constant(8)] = obj;
                              this[§§constant(9)] = prop;
                              this[§§constant(10)] = begin;
                              this[§§constant(11)](begin);
                              this[§§constant(12)](duration);
                              this[§§constant(13)] = useSeconds;
                              if(func)
                              {
                                 this[§§constant(14)] = func;
                              }
                              this[§§constant(15)](finish);
                              this[§§constant(16)] = [];
                              this[§§constant(17)](this);
                              this[§§constant(18)]();
                           }.__set__FPS.isPlaying);
                           eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                           {
                              eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                              if(!arguments[§§constant(7)])
                              {
                                 return undefined;
                              }
                              this[§§constant(8)] = obj;
                              this[§§constant(9)] = prop;
                              this[§§constant(10)] = begin;
                              this[§§constant(11)](begin);
                              this[§§constant(12)](duration);
                              this[§§constant(13)] = useSeconds;
                              if(func)
                              {
                                 this[§§constant(14)] = func;
                              }
                              this[§§constant(15)](finish);
                              this[§§constant(16)] = [];
                              this[§§constant(17)](this);
                              this[§§constant(18)]();
                           }._time._time.updateAfterEvent.getPosition(_loc2_.prevPos.onMotionChanged,0,1);
                        }
                        var _loc5_ = eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                           if(!arguments[§§constant(7)])
                           {
                              return undefined;
                           }
                           this[§§constant(8)] = obj;
                           this[§§constant(9)] = prop;
                           this[§§constant(10)] = begin;
                           this[§§constant(11)](begin);
                           this[§§constant(12)](duration);
                           this[§§constant(13)] = useSeconds;
                           if(func)
                           {
                              this[§§constant(14)] = func;
                           }
                           this[§§constant(15)](finish);
                           this[§§constant(16)] = [];
                           this[§§constant(17)](this);
                           this[§§constant(18)]();
                        }._time._time.broadcastMessage;
                        var _loc6_ = looping.startEnterFrame(_loc5_.func - eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                           if(!arguments[§§constant(7)])
                           {
                              return undefined;
                           }
                           this[§§constant(8)] = obj;
                           this[§§constant(9)] = prop;
                           this[§§constant(10)] = begin;
                           this[§§constant(11)](begin);
                           this[§§constant(12)](duration);
                           this[§§constant(13)] = useSeconds;
                           if(func)
                           {
                              this[§§constant(14)] = func;
                           }
                           this[§§constant(15)](finish);
                           this[§§constant(16)] = [];
                           this[§§constant(17)](this);
                           this[§§constant(18)]();
                        }.func,_loc5_.__set__duration - eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                           if(!arguments[§§constant(7)])
                           {
                              return undefined;
                           }
                           this[§§constant(8)] = obj;
                           this[§§constant(9)] = prop;
                           this[§§constant(10)] = begin;
                           this[§§constant(11)](begin);
                           this[§§constant(12)](duration);
                           this[§§constant(13)] = useSeconds;
                           if(func)
                           {
                              this[§§constant(14)] = func;
                           }
                           this[§§constant(15)](finish);
                           this[§§constant(16)] = [];
                           this[§§constant(17)](this);
                           this[§§constant(18)]();
                        }.__set__duration);
                        eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                           if(!arguments[§§constant(7)])
                           {
                              return undefined;
                           }
                           this[§§constant(8)] = obj;
                           this[§§constant(9)] = prop;
                           this[§§constant(10)] = begin;
                           this[§§constant(11)](begin);
                           this[§§constant(12)](duration);
                           this[§§constant(13)] = useSeconds;
                           if(func)
                           {
                              this[§§constant(14)] = func;
                           }
                           this[§§constant(15)](finish);
                           this[§§constant(16)] = [];
                           this[§§constant(17)](this);
                           this[§§constant(18)]();
                        }._listeners = looping.__get__FPS(_loc6_) * mx._fps[4];
                        eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                           if(!arguments[§§constant(7)])
                           {
                              return undefined;
                           }
                           this[§§constant(8)] = obj;
                           this[§§constant(9)] = prop;
                           this[§§constant(10)] = begin;
                           this[§§constant(11)](begin);
                           this[§§constant(12)](duration);
                           this[§§constant(13)] = useSeconds;
                           if(func)
                           {
                              this[§§constant(14)] = func;
                           }
                           this[§§constant(15)](finish);
                           this[§§constant(16)] = [];
                           this[§§constant(17)](this);
                           this[§§constant(18)]();
                        }.prevTime = looping.setPosition(_loc6_) * mx._fps[4] / 2;
                        if(eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                           if(!arguments[§§constant(7)])
                           {
                              return undefined;
                           }
                           this[§§constant(8)] = obj;
                           this[§§constant(9)] = prop;
                           this[§§constant(10)] = begin;
                           this[§§constant(11)](begin);
                           this[§§constant(12)](duration);
                           this[§§constant(13)] = useSeconds;
                           if(func)
                           {
                              this[§§constant(14)] = func;
                           }
                           this[§§constant(15)](finish);
                           this[§§constant(16)] = [];
                           this[§§constant(17)](this);
                           this[§§constant(18)]();
                        }._listeners != 0)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                           {
                              eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                              if(!arguments[§§constant(7)])
                              {
                                 return undefined;
                              }
                              this[§§constant(8)] = obj;
                              this[§§constant(9)] = prop;
                              this[§§constant(10)] = begin;
                              this[§§constant(11)](begin);
                              this[§§constant(12)](duration);
                              this[§§constant(13)] = useSeconds;
                              if(func)
                              {
                                 this[§§constant(14)] = func;
                              }
                              this[§§constant(15)](finish);
                              this[§§constant(16)] = [];
                              this[§§constant(17)](this);
                              this[§§constant(18)]();
                           }.__set__position = eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                           {
                              eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                              if(!arguments[§§constant(7)])
                              {
                                 return undefined;
                              }
                              this[§§constant(8)] = obj;
                              this[§§constant(9)] = prop;
                              this[§§constant(10)] = begin;
                              this[§§constant(11)](begin);
                              this[§§constant(12)](duration);
                              this[§§constant(13)] = useSeconds;
                              if(func)
                              {
                                 this[§§constant(14)] = func;
                              }
                              this[§§constant(15)](finish);
                              this[§§constant(16)] = [];
                              this[§§constant(17)](this);
                              this[§§constant(18)]();
                           }._listeners / looping.Infinity(eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                           {
                              eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                              if(!arguments[§§constant(7)])
                              {
                                 return undefined;
                              }
                              this[§§constant(8)] = obj;
                              this[§§constant(9)] = prop;
                              this[§§constant(10)] = begin;
                              this[§§constant(11)](begin);
                              this[§§constant(12)](duration);
                              this[§§constant(13)] = useSeconds;
                              if(func)
                              {
                                 this[§§constant(14)] = func;
                              }
                              this[§§constant(15)](finish);
                              this[§§constant(16)] = [];
                              this[§§constant(17)](this);
                              this[§§constant(18)]();
                           }._listeners);
                        }
                        eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                        {
                           eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                           if(!arguments[§§constant(7)])
                           {
                              return undefined;
                           }
                           this[§§constant(8)] = obj;
                           this[§§constant(9)] = prop;
                           this[§§constant(10)] = begin;
                           this[§§constant(11)](begin);
                           this[§§constant(12)](duration);
                           this[§§constant(13)] = useSeconds;
                           if(func)
                           {
                              this[§§constant(14)] = func;
                           }
                           this[§§constant(15)](finish);
                           this[§§constant(16)] = [];
                           this[§§constant(17)](this);
                           this[§§constant(18)]();
                        }.transitions = false;
                     }
                     eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                        if(!arguments[§§constant(7)])
                        {
                           return undefined;
                        }
                        this[§§constant(8)] = obj;
                        this[§§constant(9)] = prop;
                        this[§§constant(10)] = begin;
                        this[§§constant(11)](begin);
                        this[§§constant(12)](duration);
                        this[§§constant(13)] = useSeconds;
                        if(func)
                        {
                           this[§§constant(14)] = func;
                        }
                        this[§§constant(15)](finish);
                        this[§§constant(16)] = [];
                        this[§§constant(17)](this);
                        this[§§constant(18)]();
                     }.__set__finish = eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                        if(!arguments[§§constant(7)])
                        {
                           return undefined;
                        }
                        this[§§constant(8)] = obj;
                        this[§§constant(9)] = prop;
                        this[§§constant(10)] = begin;
                        this[§§constant(11)](begin);
                        this[§§constant(12)](duration);
                        this[§§constant(13)] = useSeconds;
                        if(func)
                        {
                           this[§§constant(14)] = func;
                        }
                        this[§§constant(15)](finish);
                        this[§§constant(16)] = [];
                        this[§§constant(17)](this);
                        this[§§constant(18)]();
                     }.__set__position * 100;
                     §§pop()[§§pop()] = §§pop();
                     eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                        if(!arguments[§§constant(7)])
                        {
                           return undefined;
                        }
                        this[§§constant(8)] = obj;
                        this[§§constant(9)] = prop;
                        this[§§constant(10)] = begin;
                        this[§§constant(11)](begin);
                        this[§§constant(12)](duration);
                        this[§§constant(13)] = useSeconds;
                        if(func)
                        {
                           this[§§constant(14)] = func;
                        }
                        this[§§constant(15)](finish);
                        this[§§constant(16)] = [];
                        this[§§constant(17)](this);
                        this[§§constant(18)]();
                     }.addListener = [3,6,4,9,7];
                     eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                        if(!arguments[§§constant(7)])
                        {
                           return undefined;
                        }
                        this[§§constant(8)] = obj;
                        this[§§constant(9)] = prop;
                        this[§§constant(10)] = begin;
                        this[§§constant(11)](begin);
                        this[§§constant(12)](duration);
                        this[§§constant(13)] = useSeconds;
                        if(func)
                        {
                           this[§§constant(14)] = func;
                        }
                        this[§§constant(15)](finish);
                        this[§§constant(16)] = [];
                        this[§§constant(17)](this);
                        this[§§constant(18)]();
                     }._fps = [0.5,2,0.5,4,4];
                     eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                        if(!arguments[§§constant(7)])
                        {
                           return undefined;
                        }
                        this[§§constant(8)] = obj;
                        this[§§constant(9)] = prop;
                        this[§§constant(10)] = begin;
                        this[§§constant(11)](begin);
                        this[§§constant(12)](duration);
                        this[§§constant(13)] = useSeconds;
                        if(func)
                        {
                           this[§§constant(14)] = func;
                        }
                        this[§§constant(15)](finish);
                        this[§§constant(16)] = [];
                        this[§§constant(17)](this);
                        this[§§constant(18)]();
                     }.update = [0.2,0.5,0.2,0.2,0.8];
                     eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(obj, prop, func, begin, finish, duration, useSeconds)
                     {
                        eval(§§constant(1))[§§constant(3)][§§constant(5)][§§constant(6)]();
                        if(!arguments[§§constant(7)])
                        {
                           return undefined;
                        }
                        this[§§constant(8)] = obj;
                        this[§§constant(9)] = prop;
                        this[§§constant(10)] = begin;
                        this[§§constant(11)](begin);
                        this[§§constant(12)](duration);
                        this[§§constant(13)] = useSeconds;
                        if(func)
                        {
                           this[§§constant(14)] = func;
                        }
                        this[§§constant(15)](finish);
                        this[§§constant(16)] = [];
                        this[§§constant(17)](this);
                        this[§§constant(18)]();
                     }.rewind = [0.5,0.5,0.3,0.8,0.7];
                     change(_global.mx.OnEnterFrameBeacon,null,1);
                     break;
                  }
                  if(eval("\x01") != 771)
                  {
                     if(eval("\x01") == 528)
                     {
                        set("\x01",eval("\x01") - 528);
                     }
                     break;
                  }
                  set("\x01",eval("\x01") - 432);
               }
            }
         }
      }
   }
}
