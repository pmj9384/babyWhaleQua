var §\x01§ = 960;
while(true)
{
   if(eval("\x01") == 960)
   {
      set("\x01",eval("\x01") - 827);
      §§push(true);
      continue;
   }
   if(eval("\x01") == 682)
   {
      set("\x01",eval("\x01") - 149);
      while(true)
      {
         var _loc2_ = §§pop() - §§pop();
         while(_loc2_ > 0)
         {
            var _loc3_ = _loc5_[_loc2_ - 1];
            var _loc7_ = (_loc3_ >>> 5 ^ _loc4_ << 2) + (_loc4_ >>> 3 ^ _loc3_ << 4) ^ (_loc6_ ^ _loc4_) + (_loc10_[_loc2_ & 3 ^ _loc8_] ^ _loc3_);
            var _loc0_ = null;
            var _loc4_ = _loc5_[_loc2_] -= _loc7_;
            _loc2_ = _loc2_ - 1;
         }
         _loc3_ = _loc5_[_loc9_ - 1];
         _loc7_ = (_loc3_ >>> 5 ^ _loc4_ << 2) + (_loc4_ >>> 3 ^ _loc3_ << 4) ^ (_loc6_ ^ _loc4_) + (_loc10_[_loc2_ & 3 ^ _loc8_] ^ _loc3_);
         _loc4_ = _loc5_[0] -= _loc7_;
         var _loc6_ -= _loc11_;
         if(_loc6_ == 0)
         {
            break;
         }
         var _loc8_ = _loc6_ >>> 2 & 3;
         §§push(_loc9_);
         §§push(1);
      }
      return _loc1_[§§constant(18)](_loc1_[§§constant(14)](_loc5_));
   }
   if(eval("\x01") == 7)
   {
      set("\x01",eval("\x01") + 303);
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
         eval(§§constant(0))[§§constant(1)][§§constant(3)][§§constant(4)] = new §\§\§constant(2)§();
      }
      §§pop();
      if(!eval(§§constant(0))[§§constant(1)][§§constant(3)][§§constant(4)][§§constant(5)])
      {
         _loc2_ = eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(5)] = function(_value, _bRange, _bSpeedHack)
         {
            if(_value == undefined || _value == null)
            {
               _value = 0;
            }
            if(_bRange == undefined || _bRange == null)
            {
               _bRange = false;
            }
            if(_bSpeedHack == undefined || _bSpeedHack == null)
            {
               _bSpeedHack = false;
            }
            this[§§constant(6)](_value);
            this[§§constant(7)](_bRange);
            this[§§constant(8)](_bSpeedHack);
         }[§§constant(9)];
         _loc2_[§§constant(10)] = function()
         {
            return Number(this[§§constant(12)](this[§§constant(11)]));
         };
         _loc2_[§§constant(6)] = function(_value)
         {
            if(this[§§constant(13)])
            {
               this[§§constant(14)] = Number(this[§§constant(12)](this[§§constant(11)]));
               if(this[§§constant(15)])
               {
                  if(this[§§constant(14)] - this[§§constant(16)] > _value || this[§§constant(14)] + this[§§constant(17)] < _value)
                  {
                     _value = this[§§constant(14)];
                     this[§§constant(11)] = this[§§constant(18)](String(_value));
                     return undefined;
                  }
               }
               if(this[§§constant(19)])
               {
                  this[§§constant(20)] = eval(§§constant(24))[§§constant(25)](getTimer() - new §\§\§constant(21)§()[§§constant(22)]() + this[§§constant(23)]);
                  if(eval(§§constant(24))[§§constant(25)](this[§§constant(20)] - this[§§constant(26)]) > 16)
                  {
                     _value = this[§§constant(14)];
                  }
                  this[§§constant(26)] = this[§§constant(20)];
               }
            }
            this[§§constant(11)] = String(this[§§constant(18)](String(_value)));
            return this[§§constant(10)]();
         };
         _loc2_[§§constant(27)] = function(_max)
         {
            if(_max == undefined || _max == null)
            {
               _max = 0;
            }
            this[§§constant(17)] = _max;
         };
         _loc2_[§§constant(28)] = function(_min)
         {
            if(_min == undefined || _min == null)
            {
               _min = 0;
            }
            this[§§constant(16)] = _min;
         };
         _loc2_[§§constant(7)] = function(bl)
         {
            if(bl == undefined || bl == null)
            {
               bl = false;
            }
            this[§§constant(15)] = bl;
            this[§§constant(13)] = this[§§constant(15)] || this[§§constant(19)];
         };
         _loc2_[§§constant(8)] = function(bl)
         {
            if(bl == undefined || bl == null)
            {
               bl = false;
            }
            this[§§constant(19)] = bl;
            this[§§constant(13)] = this[§§constant(15)] || this[§§constant(19)];
            this[§§constant(23)] = new §\§\§constant(21)§()[§§constant(22)]() - getTimer();
            this[§§constant(20)] = this[§§constant(26)] = eval(§§constant(24))[§§constant(25)](getTimer() - new §\§\§constant(21)§()[§§constant(22)]() + this[§§constant(23)]);
         };
         _loc2_[§§constant(18)] = function(str)
         {
            var _loc2_ = new §\§\§constant(29)§();
            var _loc1_ = 0;
            while(_loc1_ < str[§§constant(30)])
            {
               _loc2_[§§constant(32)](str[§§constant(31)](_loc1_));
               _loc1_ = _loc1_ + 1;
            }
            var _loc5_ = §§constant(33);
            var _loc3_ = new §\§\§constant(29)§(§§constant(49),§§constant(48),§§constant(47),§§constant(46),§§constant(45),§§constant(44),§§constant(43),§§constant(42),§§constant(41),§§constant(40),§§constant(39),§§constant(38),§§constant(37),§§constant(36),§§constant(35),§§constant(34));
            _loc1_ = 0;
            while(_loc1_ < _loc2_[§§constant(30)])
            {
               _loc5_ += _loc3_[_loc2_[_loc1_] >> 4] + _loc3_[_loc2_[_loc1_] & 0x0F];
               _loc1_ = _loc1_ + 1;
            }
            return _loc5_;
         };
         _loc2_[§§constant(12)] = function(hex)
         {
            var _loc2_ = new §\§\§constant(29)§();
            var _loc1_ = hex[§§constant(50)](0,2) != §§constant(51) ? 0 : 2;
            while(_loc1_ < hex[§§constant(30)])
            {
               _loc2_[§§constant(32)](§§constant(52)(hex[§§constant(50)](_loc1_,2),16));
               _loc1_ += 2;
            }
            var _loc4_ = new §\§\§constant(53)§(§§constant(33));
            _loc1_ = 0;
            while(_loc1_ < _loc2_[§§constant(30)])
            {
               _loc4_ += eval(§§constant(53))[§§constant(54)](_loc2_[_loc1_]);
               _loc1_ = _loc1_ + 1;
            }
            return _loc4_;
         };
         _loc2_[§§constant(13)] = false;
         _loc2_[§§constant(17)] = 0;
         _loc2_[§§constant(16)] = 0;
      }
      addr769:
      §§pop();
      break;
   }
   if(eval("\x01") == 0)
   {
      set("\x01",eval("\x01") + 568);
      if(§§pop())
      {
         set("\x01",eval("\x01") - 478);
      }
      continue;
   }
   if(eval("\x01") == 249)
   {
      set("\x01",eval("\x01") + 490);
      break;
   }
   if(eval("\x01") == 899)
   {
      set("\x01",eval("\x01") - 899);
      §§push(true);
      continue;
   }
   if(eval("\x01") == 314)
   {
      set("\x01",eval("\x01") + 579);
      if(§§pop())
      {
         set("\x01",eval("\x01") - 89);
      }
      continue;
   }
   if(eval("\x01") == 175)
   {
      set("\x01",eval("\x01") + 74);
      if(§§pop())
      {
         set("\x01",eval("\x01") + 490);
      }
      continue;
   }
   if(eval("\x01") != 193)
   {
      if(eval("\x01") == 739)
      {
         set("\x01",eval("\x01") - 449);
         §§push(true);
      }
      else if(eval("\x01") == 290)
      {
         set("\x01",eval("\x01") - 97);
         if(§§pop())
         {
            set("\x01",eval("\x01") + 706);
         }
      }
      else if(eval("\x01") == 533)
      {
         set("\x01",eval("\x01") - 526);
      }
      else
      {
         if(eval("\x01") == 310)
         {
            set("\x01",eval("\x01") - 310);
            break;
         }
         if(eval("\x01") == 708)
         {
            set("\x01",eval("\x01") - 26);
            if(§§pop())
            {
               set("\x01",eval("\x01") - 149);
            }
         }
         else
         {
            if(eval("\x01") == 744)
            {
               set("\x01",eval("\x01") + 129);
               nextFrame();
               toggleHighQuality();
               §§pop()[§§pop()] = §§pop()[length(§§pop())];
               eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(5)] = function(_value, _bRange, _bSpeedHack)
               {
                  if(_value == undefined || _value == null)
                  {
                     _value = 0;
                  }
                  if(_bRange == undefined || _bRange == null)
                  {
                     _bRange = false;
                  }
                  if(_bSpeedHack == undefined || _bSpeedHack == null)
                  {
                     _bSpeedHack = false;
                  }
                  this[§§constant(6)](_value);
                  this[§§constant(7)](_bRange);
                  this[§§constant(8)](_bSpeedHack);
               }[§§constant(11)] = String((eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(5)] = function(_value, _bRange, _bSpeedHack)
               {
                  if(_value == undefined || _value == null)
                  {
                     _value = 0;
                  }
                  if(_bRange == undefined || _bRange == null)
                  {
                     _bRange = false;
                  }
                  if(_bSpeedHack == undefined || _bSpeedHack == null)
                  {
                     _bSpeedHack = false;
                  }
                  this[§§constant(6)](_value);
                  this[§§constant(7)](_bRange);
                  this[§§constant(8)](_bSpeedHack);
               })[§§constant(18)](String(_value)));
               return (eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(5)] = function(_value, _bRange, _bSpeedHack)
               {
                  if(_value == undefined || _value == null)
                  {
                     _value = 0;
                  }
                  if(_bRange == undefined || _bRange == null)
                  {
                     _bRange = false;
                  }
                  if(_bSpeedHack == undefined || _bSpeedHack == null)
                  {
                     _bSpeedHack = false;
                  }
                  this[§§constant(6)](_value);
                  this[§§constant(7)](_bRange);
                  this[§§constant(8)](_bSpeedHack);
               })[§§constant(10)]();
            }
            if(eval("\x01") == 873)
            {
               set("\x01",eval("\x01") + 112);
               §§push(true);
            }
            else if(eval("\x01") == 260)
            {
               set("\x01",eval("\x01") - 85);
               §§push(true);
            }
            else if(eval("\x01") == 358)
            {
               set("\x01",eval("\x01") + 364);
               §§push(true);
            }
            else
            {
               if(eval("\x01") == 724)
               {
                  set("\x01",eval("\x01") + 4);
                  §§push(§§pop() | §§pop());
                  break;
               }
               if(eval("\x01") == 985)
               {
                  set("\x01",eval("\x01") - 261);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") + 4);
                  }
               }
               else if(eval("\x01") == 133)
               {
                  set("\x01",eval("\x01") + 443);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") - 218);
                  }
               }
               else if(eval("\x01") == 261)
               {
                  set("\x01",eval("\x01") + 483);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") + 129);
                  }
               }
               else if(eval("\x01") == 728)
               {
                  set("\x01",eval("\x01") - 20);
                  §§push(true);
               }
               else
               {
                  if(eval("\x01") == 576)
                  {
                     set("\x01",eval("\x01") - 218);
                     break;
                  }
                  if(eval("\x01") == 90)
                  {
                     set("\x01",eval("\x01") + 171);
                     §§push(true);
                  }
                  else
                  {
                     if(eval("\x01") == 568)
                     {
                        set("\x01",eval("\x01") - 478);
                        break;
                     }
                     if(eval("\x01") == 798)
                     {
                        set("\x01",eval("\x01") + 184);
                        if(§§pop())
                        {
                           set("\x01",eval("\x01") - 722);
                        }
                     }
                     else
                     {
                        if(eval("\x01") == 982)
                        {
                           set("\x01",eval("\x01") - 722);
                           break;
                        }
                        if(eval("\x01") == 131)
                        {
                           set("\x01",eval("\x01") - 117);
                           stop();
                           nextFrame();
                           break;
                        }
                        if(eval("\x01") == 804)
                        {
                           set("\x01",eval("\x01") - 6);
                           §§push(true);
                        }
                        else
                        {
                           if(eval("\x01") == 893)
                           {
                              set("\x01",eval("\x01") - 89);
                              §§pop()[§§pop()] = new §\§\§pop()§();
                              §§pop();
                              if(!_global.nhn.as2.security)
                              {
                                 _loc2_ = nhn.as2.security = function(t, s, d)
                                 {
                                    var SecurityNumberLight = 0;
                                    var __set__value = function(d)
                                    {
                                       this.isRange = this.isSpeedHack + random(d * 2 + 1) - d;
                                       this.prototype = this.__get__value + random(d * 2 + 1) - d;
                                    };
                                    var _loc3_ = function(d)
                                    {
                                       __set__value.decrypt(data,d);
                                       SecurityNumberLight++;
                                       if(SecurityNumberLight > bSecurity)
                                       {
                                          bRange(nClone);
                                          data.isRange = data.isSpeedHack;
                                          data.prototype = data.__get__value;
                                          delete data.isSpeedHack;
                                          delete data.__get__value;
                                       }
                                       rMIN();
                                    };
                                    if(data.isSpeedHack == undefined)
                                    {
                                       data.isSpeedHack = data.isRange;
                                    }
                                    if(data.__get__value == undefined)
                                    {
                                       data.__get__value = data.prototype;
                                    }
                                    var nClone = rMAX(_loc3_,20,d);
                                 }.encrypt;
                                 §§push(bSpeedHack(nhn.as2.security.encrypt,null,1));
                              }
                              §§pop();
                              break;
                           }
                           if(eval("\x01") == 14)
                           {
                              set("\x01",eval("\x01") + 300);
                              §§push(true);
                           }
                           else
                           {
                              if(eval("\x01") != 722)
                              {
                                 break;
                              }
                              set("\x01",eval("\x01") - 591);
                              if(§§pop())
                              {
                                 set("\x01",eval("\x01") - 117);
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
      continue;
   }
   set("\x01",eval("\x01") + 706);
   _loc2_[§§constant(15)] = false;
   _loc2_[§§constant(19)] = false;
   §§goto(addr769);
   §§push(_loc2_[§§constant(56)](§§constant(55),_loc2_[§§constant(10)],_loc2_[§§constant(6)]));
   §§push(§§constant(57)(eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(5)][§§constant(9)],null,1));
}
