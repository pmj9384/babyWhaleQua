var §\x01§ = 277;
while(true)
{
   if(eval("\x01") == 277)
   {
      set("\x01",eval("\x01") - 8);
      §§push(true);
   }
   else if(eval("\x01") == 441)
   {
      set("\x01",eval("\x01") + 10);
      §§push(true);
   }
   else if(eval("\x01") == 742)
   {
      set("\x01",eval("\x01") - 317);
      if(§§pop())
      {
         set("\x01",eval("\x01") + 408);
      }
   }
   else if(eval("\x01") == 52)
   {
      set("\x01",eval("\x01") + 690);
      §§push(true);
   }
   else
   {
      if(eval("\x01") == 16)
      {
         set("\x01",eval("\x01") + 615);
         if(!eval(§§constant(0))[§§constant(1)])
         {
            eval(§§constant(0))[§§constant(1)] extends eval(§§constant(4));
            var _loc2_ = eval(§§constant(0))[§§constant(1)] = function()
            {
               super();
               this[§§constant(2)] = 0;
               this[§§constant(3)] = false;
            }[§§constant(5)];
            _loc2_[§§constant(6)] = function(t)
            {
               this[§§constant(7)] = t;
               if(this[§§constant(7)] > 4)
               {
                  this[§§constant(8)] = true;
               }
               this[§§constant(9)](this[§§constant(7)]);
            };
            _loc2_[§§constant(10)] = function(d)
            {
               this[§§constant(11)] = d;
               if(this[§§constant(11)] == -1)
               {
                  this[§§constant(12)] = 550 + this[§§constant(13)] / 2;
               }
               else
               {
                  this[§§constant(12)] = (- this[§§constant(13)]) / 2;
               }
               this[§§constant(14)] = random(400);
               this[§§constant(15)] = this[§§constant(11)] * 100;
               this[§§constant(16)] = eval(§§constant(1))[§§constant(17)][this[§§constant(7)] - 1] * this[§§constant(11)];
               this[§§constant(18)] = true;
               this[§§constant(19)] = this[§§constant(20)];
            };
            _loc2_[§§constant(20)] = function()
            {
               this[§§constant(12)] += this[§§constant(16)];
               this[§§constant(14)] += this[§§constant(21)];
               if(this[§§constant(12)] > 650 || this[§§constant(12)] < -100 || this[§§constant(14)] > 450 || this[§§constant(14)] < -50)
               {
                  this[§§constant(22)][§§constant(22)][§§constant(23)](this);
               }
               this[§§constant(2)] = this[§§constant(2)] + 1;
               if(this[§§constant(2)] >= 30)
               {
                  this[§§constant(2)] = 0;
                  if(eval(§§constant(24))[§§constant(25)]() < eval(§§constant(1))[§§constant(26)][this[§§constant(7)] - 1])
                  {
                     this[§§constant(28)](eval(§§constant(24))[§§constant(25)]() < eval(§§constant(1))[§§constant(27)][this[§§constant(7)] - 1]);
                  }
               }
               if(this[§§constant(7)] == 1 || this[§§constant(8)])
               {
                  var _loc4_ = this[§§constant(22)][§§constant(22)][§§constant(29)];
                  var _loc3_ = this[§§constant(12)] - _loc4_[§§constant(12)];
                  var _loc2_ = this[§§constant(14)] - _loc4_[§§constant(14)];
                  var _loc5_ = eval(§§constant(24))[§§constant(30)](_loc3_ * _loc3_ + _loc2_ * _loc2_);
                  if(this[§§constant(7)] == 1 && _loc5_ < 80)
                  {
                     this[§§constant(31)]();
                  }
                  else if(this[§§constant(8)])
                  {
                     if(_loc4_[§§constant(32)])
                     {
                        if(!this[§§constant(18)] || this[§§constant(3)])
                        {
                           this[§§constant(3)] = false;
                           this[§§constant(28)](true);
                        }
                     }
                     else if(eval(§§constant(24))[§§constant(33)](_loc3_) < 120 && eval(§§constant(24))[§§constant(33)](_loc2_) < 90)
                     {
                        this[§§constant(31)]();
                     }
                     else
                     {
                        this[§§constant(3)] = false;
                     }
                  }
               }
            };
            _loc2_[§§constant(31)] = function()
            {
               if(!this[§§constant(3)])
               {
                  this[§§constant(3)] = true;
                  this[§§constant(28)](!this[§§constant(8)]);
               }
            };
            _loc2_[§§constant(28)] = function(high)
            {
               this[§§constant(18)] = high;
               var _loc4_ = undefined;
               if(!high)
               {
                  this[§§constant(34)][§§constant(9)](this[§§constant(34)][§§constant(35)]);
                  if(this[§§constant(8)])
                  {
                     this[§§constant(34)][§§constant(36)](1);
                  }
                  _loc4_ = eval(§§constant(1))[§§constant(37)][this[§§constant(7)] - 1];
                  this[§§constant(21)] = eval(§§constant(24))[§§constant(25)]() * 1 - 0.5;
               }
               else
               {
                  this[§§constant(11)] = random(2) * 2 - 1;
                  this[§§constant(34)][§§constant(36)](1);
                  _loc4_ = eval(§§constant(1))[§§constant(17)][this[§§constant(7)] - 1];
                  this[§§constant(21)] = eval(§§constant(24))[§§constant(25)]() * 2 - 1;
               }
               this[§§constant(16)] = _loc4_ * this[§§constant(11)];
               var _loc5_ = this[§§constant(22)][§§constant(22)][§§constant(29)];
               if(this[§§constant(7)] == 1 && high && this[§§constant(3)])
               {
                  var _loc6_ = eval(§§constant(24))[§§constant(38)](_loc5_[§§constant(14)] - this[§§constant(14)],_loc5_[§§constant(12)] - this[§§constant(12)]) + 3.141592653589793 * (160 + random(40)) / 180;
                  this[§§constant(16)] = eval(§§constant(24))[§§constant(39)](_loc6_) * eval(§§constant(1))[§§constant(17)][0];
                  this[§§constant(21)] = eval(§§constant(24))[§§constant(40)](_loc6_) * eval(§§constant(1))[§§constant(17)][0] / 1.5;
                  if(this[§§constant(16)] != 0)
                  {
                     this[§§constant(11)] = this[§§constant(16)] / eval(§§constant(24))[§§constant(33)](this[§§constant(16)]);
                  }
                  this[§§constant(15)] = this[§§constant(11)] * 100;
               }
               if(this[§§constant(8)] && (!high || this[§§constant(3)]) && !_loc5_[§§constant(32)] && _loc5_[§§constant(41)] != eval(§§constant(42))[§§constant(43)])
               {
                  if(this[§§constant(3)])
                  {
                     this[§§constant(34)][§§constant(9)](this[§§constant(34)][§§constant(35)]);
                     this[§§constant(22)][§§constant(22)][§§constant(45)][§§constant(46)](_global[§§constant(42)][§§constant(44)],0,1);
                  }
                  _loc5_ = this[§§constant(22)][§§constant(22)][§§constant(29)];
                  _loc6_ = eval(§§constant(24))[§§constant(38)](_loc5_[§§constant(14)] - this[§§constant(14)],_loc5_[§§constant(12)] - this[§§constant(12)]);
                  this[§§constant(16)] = eval(§§constant(24))[§§constant(39)](_loc6_) * eval(§§constant(1))[§§constant(37)][4];
                  this[§§constant(21)] = eval(§§constant(24))[§§constant(40)](_loc6_) * eval(§§constant(1))[§§constant(37)][4] / 2;
                  if(this[§§constant(16)] != 0)
                  {
                     this[§§constant(11)] = this[§§constant(16)] / eval(§§constant(24))[§§constant(33)](this[§§constant(16)]);
                  }
                  this[§§constant(3)] = false;
               }
               this[§§constant(15)] = this[§§constant(11)] * 100;
            };
            eval(§§constant(0))[§§constant(1)] = function()
            {
               super();
               this[§§constant(2)] = 0;
               this[§§constant(3)] = false;
            }[§§constant(17)] = [3,6,4,9,7];
            eval(§§constant(0))[§§constant(1)] = function()
            {
               super();
               this[§§constant(2)] = 0;
               this[§§constant(3)] = false;
            }[§§constant(37)] = [0.5,2,0.5,4,4];
            eval(§§constant(0))[§§constant(1)] = function()
            {
               super();
               this[§§constant(2)] = 0;
               this[§§constant(3)] = false;
            }[§§constant(27)] = [0.2,0.5,0.2,0.2,0.8];
            eval(§§constant(0))[§§constant(1)] = function()
            {
               super();
               this[§§constant(2)] = 0;
               this[§§constant(3)] = false;
            }[§§constant(26)] = [0.5,0.5,0.3,0.8,0.7];
            §§push(§§constant(47)(eval(§§constant(0))[§§constant(1)][§§constant(5)],null,1));
         }
         §§pop();
         break;
      }
      if(eval("\x01") == 442)
      {
         set("\x01",eval("\x01") - 375);
         break;
      }
      if(eval("\x01") == 313)
      {
         set("\x01",eval("\x01") + 45);
         §§push(true);
      }
      else if(eval("\x01") == 523)
      {
         set("\x01",eval("\x01") - 280);
         §§push(true);
      }
      else
      {
         if(eval("\x01") == 98)
         {
            set("\x01",eval("\x01") + 215);
            break;
         }
         if(eval("\x01") == 785)
         {
            set("\x01",eval("\x01") - 719);
            §§push(§§pop()[§§pop()]);
            break;
         }
         if(eval("\x01") == 358)
         {
            set("\x01",eval("\x01") + 202);
            if(§§pop())
            {
               set("\x01",eval("\x01") - 154);
            }
         }
         else if(eval("\x01") == 451)
         {
            set("\x01",eval("\x01") - 9);
            if(§§pop())
            {
               set("\x01",eval("\x01") - 375);
            }
         }
         else if(eval("\x01") == 234)
         {
            set("\x01",eval("\x01") + 180);
            §§push(true);
         }
         else
         {
            if(eval("\x01") == 612)
            {
               set("\x01",eval("\x01") + 149);
               break;
            }
            if(eval("\x01") == 406)
            {
               set("\x01",eval("\x01") + 332);
               §§push(true);
            }
            else if(eval("\x01") == 243)
            {
               set("\x01",eval("\x01") + 598);
               if(§§pop())
               {
                  set("\x01",eval("\x01") - 607);
               }
            }
            else
            {
               if(eval("\x01") == 774)
               {
                  set("\x01",eval("\x01") - 333);
                  break;
               }
               if(eval("\x01") == 833)
               {
                  set("\x01",eval("\x01") - 514);
                  §§push(true);
               }
               else if(eval("\x01") == 269)
               {
                  set("\x01",eval("\x01") + 293);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") - 39);
                  }
               }
               else if(eval("\x01") == 67)
               {
                  set("\x01",eval("\x01") + 636);
                  §§push(true);
               }
               else if(eval("\x01") == 351)
               {
                  set("\x01",eval("\x01") - 253);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") + 215);
                  }
               }
               else
               {
                  if(eval("\x01") == 562)
                  {
                     set("\x01",eval("\x01") - 39);
                     break;
                  }
                  if(eval("\x01") == 294)
                  {
                     set("\x01",eval("\x01") - 242);
                     duplicateMovieClip(§§pop(),§§pop(),§§pop());
                     set(§§pop(),§§pop());
                     break;
                  }
                  if(eval("\x01") == 414)
                  {
                     set("\x01",eval("\x01") + 371);
                     if(§§pop())
                     {
                        set("\x01",eval("\x01") - 719);
                     }
                  }
                  else if(eval("\x01") == 738)
                  {
                     set("\x01",eval("\x01") + 36);
                     if(§§pop())
                     {
                        set("\x01",eval("\x01") - 333);
                     }
                  }
                  else if(eval("\x01") == 703)
                  {
                     set("\x01",eval("\x01") - 409);
                     if(§§pop())
                     {
                        set("\x01",eval("\x01") - 242);
                     }
                  }
                  else
                  {
                     if(eval("\x01") == 841)
                     {
                        set("\x01",eval("\x01") - 607);
                        break;
                     }
                     if(eval("\x01") == 560)
                     {
                        set("\x01",eval("\x01") - 154);
                        §§push(mbchr(new §\§\§pop()§()));
                        break;
                     }
                     if(eval("\x01") == 66)
                     {
                        set("\x01",eval("\x01") + 285);
                        §§push(true);
                     }
                     else
                     {
                        if(eval("\x01") == 425)
                        {
                           set("\x01",eval("\x01") + 408);
                           §§push(§§pop() + 1);
                           break;
                        }
                        if(eval("\x01") == 319)
                        {
                           set("\x01",eval("\x01") + 293);
                           if(§§pop())
                           {
                              set("\x01",eval("\x01") + 149);
                           }
                        }
                        else
                        {
                           if(eval("\x01") != 761)
                           {
                              if(eval("\x01") == 631)
                              {
                                 set("\x01",eval("\x01") - 631);
                              }
                              break;
                           }
                           set("\x01",eval("\x01") - 745);
                        }
                     }
                  }
               }
            }
         }
      }
   }
}
