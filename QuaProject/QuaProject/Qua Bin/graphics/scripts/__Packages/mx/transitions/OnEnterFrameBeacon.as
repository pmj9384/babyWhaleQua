var §\x01§ = 937;
while(true)
{
   if(eval("\x01") == 937)
   {
      set("\x01",eval("\x01") - 727);
      §§push(true);
   }
   else
   {
      if(eval("\x01") == 310)
      {
         set("\x01",eval("\x01") + 356);
         break;
      }
      if(eval("\x01") == 344)
      {
         set("\x01",eval("\x01") + 625);
         §§push(true);
      }
      else if(eval("\x01") == 210)
      {
         set("\x01",eval("\x01") + 100);
         if(§§pop())
         {
            set("\x01",eval("\x01") + 356);
         }
      }
      else if(eval("\x01") == 788)
      {
         set("\x01",eval("\x01") - 583);
         §§push(true);
      }
      else
      {
         if(eval("\x01") == 834)
         {
            set("\x01",eval("\x01") - 10);
            §§push(§§pop() >>> (§§pop() >>> §§pop()));
            break;
         }
         if(eval("\x01") == 866)
         {
            set("\x01",eval("\x01") - 555);
            §§push(true);
         }
         else
         {
            if(eval("\x01") == 644)
            {
               set("\x01",eval("\x01") + 144);
               break;
            }
            if(eval("\x01") == 666)
            {
               set("\x01",eval("\x01") + 195);
               §§push(true);
            }
            else
            {
               if(eval("\x01") == 953)
               {
                  set("\x01",eval("\x01") - 591);
                  §§pop()();
                  _loc1_[§§constant(6)] = false;
                  _loc1_[§§constant(26)]({(§§constant(24)):§§constant(28),(§§constant(25)):_loc1_[§§constant(5)]});
                  §§pop()[§§pop()] = §§pop();
                  _loc2_[§§constant(29)] = function()
                  {
                     if(this[§§constant(6)] && !this[§§constant(7)])
                     {
                        this[§§constant(7)] = true;
                        §§constant(27)(this[§§constant(21)]);
                        this[§§constant(26)]({(§§constant(24)):§§constant(29),(§§constant(25)):this[§§constant(5)]});
                     }
                  };
                  _loc2_[§§constant(30)] = function()
                  {
                     if(this[§§constant(6)] && this[§§constant(7)])
                     {
                        this[§§constant(7)] = false;
                        this[§§constant(16)] = getTimer() - this[§§constant(15)];
                        this[§§constant(22)]();
                        this[§§constant(21)] = §§constant(23)(this,§§constant(22),this[§§constant(15)]);
                        this[§§constant(26)]({(§§constant(24)):§§constant(30),(§§constant(25)):this[§§constant(5)]});
                     }
                  };
                  _loc2_[§§constant(31)] = function()
                  {
                     return this[§§constant(7)];
                  };
                  _loc2_[§§constant(32)] = function(obj)
                  {
                     this[§§constant(33)](§§constant(29),obj);
                     this[§§constant(33)](§§constant(30),obj);
                  };
                  _loc2_[§§constant(34)] = function(obj)
                  {
                     this[§§constant(35)](§§constant(29),obj);
                     this[§§constant(35)](§§constant(30),obj);
                  };
                  _loc2_[§§constant(36)] = function()
                  {
                     return this[§§constant(5)] + (this[§§constant(16)] - getTimer());
                  };
                  _loc2_[§§constant(37)] = function()
                  {
                     return this[§§constant(14)] - (this[§§constant(5)] + (this[§§constant(16)] - getTimer()));
                  };
                  _loc2_[§§constant(38)] = function()
                  {
                     return this[§§constant(37)]();
                  };
                  _loc2_[§§constant(22)] = function()
                  {
                     var _loc2_ = getTimer();
                     var _loc3_ = this[§§constant(5)];
                     this[§§constant(5)] += this[§§constant(16)] - _loc2_;
                     this[§§constant(39)] = _loc3_ - this[§§constant(5)] - this[§§constant(15)];
                     this[§§constant(16)] = _loc2_;
                     this[§§constant(26)]({(§§constant(24)):§§constant(15),(§§constant(25)):this[§§constant(5)]});
                     if(--this[§§constant(17)] == 0)
                     {
                        this[§§constant(20)]();
                        this[§§constant(26)]({(§§constant(24)):§§constant(40),(§§constant(25)):this[§§constant(5)]});
                     }
                  };
                  _loc2_[§§constant(41)] = function()
                  {
                     var _loc3_ = arguments;
                     var §§constant(42) = _loc3_[0];
                     var §§constant(43) = _loc3_[1];
                     var §§constant(44) = _loc3_[2];
                     if(typeof eval(§§constant(42)) == §§constant(45) && typeof eval(§§constant(43)) == §§constant(46))
                     {
                        set(§§constant(44),eval(§§constant(43)));
                        set(§§constant(43),eval(§§constant(42)));
                        set(§§constant(42),null);
                        var _loc6_ = 2;
                     }
                     else
                     {
                        if(!(eval(§§constant(42)) instanceof eval(§§constant(2)) && typeof (§\§\§constant(43)§ = eval(§§constant(42))[eval(§§constant(43))]) == §§constant(45) && typeof eval(§§constant(44)) == §§constant(46)))
                        {
                           return false;
                        }
                        _loc6_ = 3;
                     }
                     _loc3_[§§constant(47)](0,_loc6_);
                     var §§constant(48) = this[§§constant(37)]();
                     var _loc4_ = {(§§constant(48)):eval(§§constant(48)),(§§constant(44)):eval(§§constant(44)),(§§constant(49)):this,(§§constant(50)):_loc3_,(§§constant(43)):eval(§§constant(43)),(§§constant(42)):eval(§§constant(42)),(§§constant(15)):function(e)
                     {
                        var _loc2_ = e[§§constant(51)][§§constant(37)]();
                        if(_loc2_ - this[§§constant(48)] > this[§§constant(44)])
                        {
                           this[§§constant(43)][§§constant(52)](this[§§constant(42)],this[§§constant(50)]);
                           this[§§constant(49)][§§constant(35)](§§constant(15),this);
                        }
                     }};
                     this[§§constant(33)](§§constant(15),_loc4_);
                     return _loc4_;
                  };
                  _loc1_[§§constant(53)] = function()
                  {
                     var _loc2_ = arguments;
                     var §§constant(42) = _loc2_[0];
                     var §§constant(43) = _loc2_[1];
                     var _loc3_ = _loc2_[2];
                     if(typeof eval(§§constant(42)) == §§constant(45) && typeof eval(§§constant(43)) == §§constant(46))
                     {
                        _loc3_ = eval(§§constant(43));
                        set(§§constant(43),eval(§§constant(42)));
                        set(§§constant(42),null);
                        var _loc4_ = 2;
                     }
                     else
                     {
                        if(!(typeof (§\§\§constant(43)§ = eval(§§constant(42))[eval(§§constant(43))]) == §§constant(45) && typeof _loc3_ == §§constant(46)))
                        {
                           return false;
                        }
                        _loc4_ = 3;
                     }
                     _loc2_[§§constant(47)](0,_loc4_);
                     var _loc5_ = function(array)
                     {
                        eval(§§constant(43))[§§constant(52)](eval(§§constant(42)),array);
                        §§constant(27)(eval(§§constant(54)));
                     };
                     var §§constant(54) = §§constant(23)(_loc5_,_loc3_,_loc2_);
                     return eval(§§constant(54));
                  };
                  _loc2_[§§constant(39)] = 0;
                  §§constant(55)(eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(12)],null,1);
                  break;
               }
               if(eval("\x01") == 236)
               {
                  set("\x01",eval("\x01") + 408);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") + 144);
                  }
               }
               else
               {
                  if(eval("\x01") == 870)
                  {
                     set("\x01",eval("\x01") + 13);
                     break;
                  }
                  if(eval("\x01") == 165)
                  {
                     set("\x01",eval("\x01") + 130);
                     nextFrame();
                     break;
                  }
                  if(eval("\x01") == 861)
                  {
                     set("\x01",eval("\x01") + 92);
                     if(§§pop())
                     {
                        set("\x01",eval("\x01") - 591);
                     }
                  }
                  else
                  {
                     if(eval("\x01") == 70)
                     {
                        set("\x01",eval("\x01") + 908);
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
                           }[§§constant(6)] = function()
                           {
                              var _loc4_ = _global[§§constant(7)];
                              if(!_root[§§constant(8)])
                              {
                                 eval(§§constant(1))[§§constant(3)][§§constant(9)][§§constant(10)](_loc4_);
                                 var _loc3_ = _root[§§constant(11)](§§constant(8),9876);
                                 _loc3_[§§constant(12)] = function()
                                 {
                                    _global[§§constant(7)][§§constant(13)](§§constant(12));
                                 };
                              }
                           };
                           eval(§§constant(1))[§§constant(3)][§§constant(4)] = function()
                           {
                           }[§§constant(14)] = §§constant(15);
                           §§push(§§constant(16)(eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(5)],null,1));
                        }
                        §§pop();
                        break;
                     }
                     if(eval("\x01") == 362)
                     {
                        set("\x01",eval("\x01") - 140);
                        §§push(true);
                     }
                     else if(eval("\x01") == 205)
                     {
                        set("\x01",eval("\x01") + 665);
                        if(§§pop())
                        {
                           set("\x01",eval("\x01") + 13);
                        }
                     }
                     else if(eval("\x01") == 295)
                     {
                        set("\x01",eval("\x01") - 59);
                        §§push(true);
                     }
                     else
                     {
                        if(eval("\x01") == 820)
                        {
                           set("\x01",eval("\x01") - 476);
                           set(§§pop(),§§pop() - 269);
                           break;
                        }
                        if(eval("\x01") == 222)
                        {
                           set("\x01",eval("\x01") - 57);
                           if(§§pop())
                           {
                              set("\x01",eval("\x01") + 130);
                           }
                        }
                        else if(eval("\x01") == 883)
                        {
                           set("\x01",eval("\x01") - 363);
                           §§push(true);
                        }
                        else if(eval("\x01") == 520)
                        {
                           set("\x01",eval("\x01") + 17);
                           if(§§pop())
                           {
                              set("\x01",eval("\x01") + 329);
                           }
                        }
                        else if(eval("\x01") == 824)
                        {
                           set("\x01",eval("\x01") - 754);
                        }
                        else
                        {
                           if(eval("\x01") == 537)
                           {
                              set("\x01",eval("\x01") + 329);
                              break;
                           }
                           if(eval("\x01") == 311)
                           {
                              set("\x01",eval("\x01") + 509);
                              if(§§pop())
                              {
                                 set("\x01",eval("\x01") - 476);
                              }
                           }
                           else
                           {
                              if(eval("\x01") != 969)
                              {
                                 if(eval("\x01") == 978)
                                 {
                                    set("\x01",eval("\x01") - 978);
                                 }
                                 break;
                              }
                              set("\x01",eval("\x01") - 135);
                              if(§§pop())
                              {
                                 set("\x01",eval("\x01") - 10);
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
}
