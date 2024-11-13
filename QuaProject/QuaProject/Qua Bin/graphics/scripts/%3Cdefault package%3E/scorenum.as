var §\x01§ = 278;
loop0:
while(true)
{
   if(eval("\x01") != 278)
   {
      if(eval("\x01") == 323)
      {
         set("\x01",eval("\x01") - 14);
         var _loc2_ = §§pop()[n];
         if(pan != undefined)
         {
            _loc2_[§§constant(25)](pan);
         }
         addr811:
         §§pop()[§§pop()] = §§pop();
         _loc2_[§§constant(26)] = function(n, offset, loop, vol, pan)
         {
            var _loc2_ = this[§§constant(7)][n];
            if(vol > 0)
            {
               _loc2_[§§constant(21)](vol);
               if(pan != undefined)
               {
                  _loc2_[§§constant(25)](pan);
               }
            }
            _loc2_[§§constant(26)](offset,loop);
         };
         _loc2_[§§constant(27)] = function(n)
         {
            this[§§constant(7)][n][§§constant(27)]();
         };
      }
      if(eval("\x01") == 235)
      {
         set("\x01",eval("\x01") + 108);
         if(§§pop())
         {
            set("\x01",eval("\x01") - 250);
         }
      }
      else if(eval("\x01") == 311)
      {
         set("\x01",eval("\x01") + 156);
         if(§§pop())
         {
            set("\x01",eval("\x01") - 406);
         }
      }
      else
      {
         if(eval("\x01") != 797)
         {
            if(eval("\x01") == 343)
            {
               set("\x01",eval("\x01") - 250);
               break;
            }
            if(eval("\x01") == 467)
            {
               set("\x01",eval("\x01") - 406);
            }
            else
            {
               if(eval("\x01") == 320)
               {
                  set("\x01",eval("\x01") + 579);
                  break;
               }
               if(eval("\x01") == 444)
               {
                  set("\x01",eval("\x01") + 353);
                  §§push(true);
                  continue;
               }
               if(eval("\x01") == 93)
               {
                  set("\x01",eval("\x01") + 176);
                  §§push(true);
                  continue;
               }
               if(eval("\x01") == 688)
               {
                  set("\x01",eval("\x01") - 365);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") - 14);
                  }
                  continue;
               }
               if(eval("\x01") == 982)
               {
                  set("\x01",eval("\x01") - 498);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") - 40);
                  }
                  continue;
               }
               if(eval("\x01") == 61)
               {
                  set("\x01",eval("\x01") + 627);
                  §§push(true);
                  continue;
               }
               if(eval("\x01") == 309)
               {
                  set("\x01",eval("\x01") - 265);
                  §§push(true);
                  continue;
               }
               if(eval("\x01") == 981)
               {
                  set("\x01",eval("\x01") - 746);
                  §§push(true);
                  continue;
               }
               if(eval("\x01") == 67)
               {
                  set("\x01",eval("\x01") + 289);
                  Object.registerClass("scorenum",nhn.game.Digit);
                  break;
               }
               if(eval("\x01") == 766)
               {
                  set("\x01",eval("\x01") + 215);
                  return §§pop();
               }
               if(eval("\x01") == 269)
               {
                  set("\x01",eval("\x01") + 51);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") + 579);
                  }
                  continue;
               }
               if(eval("\x01") == 899)
               {
                  set("\x01",eval("\x01") + 83);
                  §§push(true);
                  continue;
               }
               if(eval("\x01") == 44)
               {
                  set("\x01",eval("\x01") + 722);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") + 215);
                  }
                  continue;
               }
               if(eval("\x01") == 484)
               {
                  set("\x01",eval("\x01") - 40);
                  §§pop()[§§pop()] = new §\§\§pop()§();
                  §§pop();
                  if(!eval(§§constant(0))[§§constant(1)][§§constant(3)][§§constant(4)])
                  {
                     _loc2_ = eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(mc, b, n)
                     {
                        this[§§constant(5)] = mc;
                        this[§§constant(6)] = b;
                        this[§§constant(7)] = new §\§\§constant(8)§(n);
                        this[§§constant(9)] = false;
                        if(n > 0)
                        {
                           this[§§constant(10)](n);
                        }
                     }[§§constant(11)];
                     _loc2_[§§constant(10)] = function(n)
                     {
                        var _loc3_ = undefined;
                        var _loc2_ = 0;
                        while(_loc2_ < n)
                        {
                           _loc3_ = this[§§constant(5)][§§constant(13)](§§constant(12) + (this[§§constant(6)] + _loc2_),this[§§constant(6)] + _loc2_);
                           this[§§constant(7)][_loc2_] = new §\§\§constant(14)§(_loc3_);
                           this[§§constant(7)][_loc2_][§§constant(15)] = _loc3_;
                           _loc2_ = _loc2_ + 1;
                        }
                        this[§§constant(9)] = true;
                     };
                     _loc2_[§§constant(16)] = function()
                     {
                        if(!this[§§constant(9)])
                        {
                           this[§§constant(10)](arguments[§§constant(17)]);
                        }
                        var _loc3_ = 0;
                        while(_loc3_ < arguments[§§constant(17)])
                        {
                           this[§§constant(7)][_loc3_][§§constant(18)](arguments[_loc3_]);
                           this[§§constant(19)][_loc3_] = 100;
                           _loc3_ = _loc3_ + 1;
                        }
                     };
                     _loc2_[§§constant(20)] = function()
                     {
                        var _loc3_ = 0;
                        while(_loc3_ < arguments[§§constant(17)])
                        {
                           this[§§constant(7)][_loc3_][§§constant(21)](arguments[_loc3_]);
                           this[§§constant(19)][_loc3_] = arguments[_loc3_];
                           _loc3_ = _loc3_ + 1;
                        }
                     };
                     _loc2_[§§constant(22)] = function()
                     {
                        var _loc2_ = 0;
                        while(_loc2_ < this[§§constant(19)][§§constant(17)])
                        {
                           this[§§constant(7)][_loc2_][§§constant(21)](0);
                           _loc2_ = _loc2_ + 1;
                        }
                     };
                     _loc2_[§§constant(23)] = function()
                     {
                        var _loc2_ = 0;
                        while(_loc2_ < this[§§constant(19)][§§constant(17)])
                        {
                           this[§§constant(7)][_loc2_][§§constant(21)](this[§§constant(19)][_loc2_]);
                           _loc2_ = _loc2_ + 1;
                        }
                     };
                     _loc2_[§§constant(24)] = function()
                     {
                        var _loc3_ = 0;
                        while(_loc3_ < arguments[§§constant(17)])
                        {
                           this[§§constant(7)][_loc3_][§§constant(25)](arguments[_loc3_]);
                           _loc3_ = _loc3_ + 1;
                        }
                     };
                     _loc2_[§§constant(21)] = function(n, vol, register)
                     {
                        var _loc3_ = this[§§constant(7)][n];
                        if(vol != undefined)
                        {
                           _loc3_[§§constant(21)](vol);
                        }
                        if(register != undefined)
                        {
                           this[§§constant(19)][n] = vol;
                        }
                     };
                     §§goto(addr811);
                     §§push(_loc2_);
                     §§push(§§constant(25));
                  }
               }
               else
               {
                  if(eval("\x01") != 10)
                  {
                     if(eval("\x01") == 356)
                     {
                        set("\x01",eval("\x01") - 356);
                     }
                     break;
                  }
                  set("\x01",eval("\x01") + 57);
                  loop1:
                  while(true)
                  {
                     if(§§pop() == 550)
                     {
                        set("\x01",eval("\x01") - 507);
                        if(§§pop())
                        {
                           set("\x01",eval("\x01") + 552);
                        }
                     }
                     else if(eval("\x01") == 595)
                     {
                        set("\x01",eval("\x01") - 136);
                        §§push(true);
                     }
                     else
                     {
                        if(eval("\x01") == 905)
                        {
                           set("\x01",eval("\x01") - 484);
                           §§push(§§pop() >>> targetPath(§§pop() gt §§pop() << (§§pop() | §§pop())));
                           break loop0;
                        }
                        if(eval("\x01") == 16)
                        {
                           set("\x01",eval("\x01") + 151);
                           §§push(true);
                        }
                        else if(eval("\x01") == 899)
                        {
                           §§push("\x01");
                           §§push("\x01");
                        }
                        else if(eval("\x01") == 244)
                        {
                           set("\x01",eval("\x01") + 655);
                           if(§§pop())
                           {
                              set("\x01",eval("\x01") - 883);
                           }
                        }
                        else
                        {
                           if(eval("\x01") == 719)
                           {
                              set("\x01",eval("\x01") - 515);
                              §§push(§§pop() >>> §§pop());
                              break loop0;
                           }
                           if(eval("\x01") != 459)
                           {
                              break loop0;
                           }
                           set("\x01",eval("\x01") + 260);
                           if(§§pop())
                           {
                              set("\x01",eval("\x01") - 515);
                           }
                        }
                     }
                     while(true)
                     {
                        if(eval("\x01") == 476)
                        {
                           set("\x01",eval("\x01") + 74);
                           §§push(true);
                           continue;
                        }
                        if(eval("\x01") == 876)
                        {
                           set("\x01",eval("\x01") - 176);
                           §§push(true);
                           continue;
                        }
                        if(eval("\x01") == 151)
                        {
                           set("\x01",eval("\x01") + 685);
                           if(§§pop())
                           {
                              set("\x01",eval("\x01") + 40);
                           }
                           continue;
                        }
                        if(eval("\x01") == 47)
                        {
                           set("\x01",eval("\x01") + 96);
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
                              _loc2_ = eval(§§constant(1))[§§constant(3)][§§constant(4)] = function(t, s, d)
                              {
                                 var §§constant(5) = 0;
                                 var §§constant(6) = function(d)
                                 {
                                    this[§§constant(7)] = this[§§constant(8)] + random(d * 2 + 1) - d;
                                    this[§§constant(9)] = this[§§constant(10)] + random(d * 2 + 1) - d;
                                 };
                                 var _loc3_ = function(d)
                                 {
                                    eval(§§constant(6))[§§constant(12)](eval(§§constant(11)),d);
                                    set(§§constant(5),eval(§§constant(5)) + 1);
                                    if(eval(§§constant(5)) > eval(§§constant(13)))
                                    {
                                       §§constant(15)(eval(§§constant(14)));
                                       eval(§§constant(11))[§§constant(7)] = eval(§§constant(11))[§§constant(8)];
                                       eval(§§constant(11))[§§constant(9)] = eval(§§constant(11))[§§constant(10)];
                                       delete eval(§§constant(11))[§§constant(8)];
                                       delete eval(§§constant(11))[§§constant(10)];
                                    }
                                    §§constant(16)();
                                 };
                                 if(eval(§§constant(11))[§§constant(8)] == undefined)
                                 {
                                    eval(§§constant(11))[§§constant(8)] = eval(§§constant(11))[§§constant(7)];
                                 }
                                 if(eval(§§constant(11))[§§constant(10)] == undefined)
                                 {
                                    eval(§§constant(11))[§§constant(10)] = eval(§§constant(11))[§§constant(9)];
                                 }
                                 var §§constant(14) = §§constant(17)(_loc3_,20,d);
                              }[§§constant(18)];
                              §§push(§§constant(19)(eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(18)],null,1));
                           }
                           §§pop();
                           break loop0;
                        }
                        if(eval("\x01") == 43)
                        {
                           set("\x01",eval("\x01") + 552);
                           break loop0;
                        }
                        if(eval("\x01") == 836)
                        {
                           set("\x01",eval("\x01") + 40);
                           break loop0;
                        }
                        if(eval("\x01") == 233)
                        {
                           set("\x01",eval("\x01") + 11);
                           §§push(true);
                           continue;
                        }
                        if(eval("\x01") == 421)
                        {
                           set("\x01",eval("\x01") - 374);
                           continue;
                        }
                        if(eval("\x01") == 26)
                        {
                           set("\x01",eval("\x01") + 207);
                           break loop0;
                        }
                        if(eval("\x01") == 204)
                        {
                           set("\x01",eval("\x01") - 53);
                           §§push(true);
                           continue;
                        }
                        if(eval("\x01") == 167)
                        {
                           set("\x01",eval("\x01") + 738);
                           if(§§pop())
                           {
                              set("\x01",eval("\x01") - 484);
                           }
                           continue;
                        }
                        if(eval("\x01") == 700)
                        {
                           set("\x01",eval("\x01") - 674);
                           if(§§pop())
                           {
                              set("\x01",eval("\x01") + 207);
                           }
                           continue;
                        }
                        if(eval("\x01") == 143)
                        {
                           set("\x01",eval("\x01") - 143);
                           break loop0;
                        }
                        continue loop1;
                     }
                  }
               }
            }
            set(§§pop(),eval(§§pop()) - 883);
            break;
         }
         set("\x01",eval("\x01") - 787);
         if(§§pop())
         {
            set("\x01",eval("\x01") + 57);
         }
      }
      continue;
      _loc2_[§§constant(28)] = function()
      {
         var _loc2_ = 0;
         while(_loc2_ < this[§§constant(7)][§§constant(17)])
         {
            this[§§constant(7)][_loc2_][§§constant(27)]();
            _loc2_ = _loc2_ + 1;
         }
      };
      _loc2_[§§constant(29)] = function()
      {
         return §§constant(30);
      };
      _loc2_[§§constant(19)] = [];
      §§push(§§constant(31)(eval(§§constant(1))[§§constant(3)][§§constant(4)][§§constant(11)],null,1));
      §§pop();
      break;
   }
   set("\x01",eval("\x01") + 33);
   §§push(true);
}
