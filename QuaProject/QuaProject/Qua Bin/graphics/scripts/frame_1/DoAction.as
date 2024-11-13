var §\x01§ = 228;
while(true)
{
   if(eval("\x01") == 228)
   {
      set("\x01",eval("\x01") - 101);
      §§push(true);
   }
   else if(eval("\x01") == 265)
   {
      set("\x01",eval("\x01") - 179);
      if(§§pop())
      {
         set("\x01",eval("\x01") + 560);
      }
   }
   else if(eval("\x01") == 151)
   {
      set("\x01",eval("\x01") + 635);
      §§push(true);
   }
   else
   {
      if(eval("\x01") == 86)
      {
         set("\x01",eval("\x01") + 560);
         break;
      }
      if(eval("\x01") == 657)
      {
         set("\x01",eval("\x01") - 214);
         ifFrameLoaded(§§pop())
         {
         }
      }
      if(eval("\x01") == 356)
      {
         set("\x01",eval("\x01") + 454);
         break;
      }
      if(eval("\x01") == 831)
      {
         set("\x01",eval("\x01") - 566);
         §§push(true);
      }
      else
      {
         if(eval("\x01") == 728)
         {
            set("\x01",eval("\x01") - 83);
            break;
         }
         if(eval("\x01") == 163)
         {
            set("\x01",eval("\x01") + 145);
            tellTarget(§§pop() or §§pop() / (§§pop() * §§pop().substr(§§pop(),§§pop())))
            {
               tellTarget(§§pop() and int(§§pop().substr(§§pop(),§§pop())))
               {
                  break;
               }
            }
         }
         if(eval("\x01") == 144)
         {
            set("\x01",eval("\x01") + 503);
            §§push(true);
         }
         else if(eval("\x01") == 646)
         {
            set("\x01",eval("\x01") - 603);
            §§push(true);
         }
         else if(eval("\x01") == 127)
         {
            set("\x01",eval("\x01") + 419);
            if(§§pop())
            {
               set("\x01",eval("\x01") + 285);
            }
         }
         else if(eval("\x01") == 647)
         {
            set("\x01",eval("\x01") + 81);
            if(§§pop())
            {
               set("\x01",eval("\x01") - 83);
            }
         }
         else if(eval("\x01") == 946)
         {
            set("\x01",eval("\x01") - 556);
            §§push(true);
         }
         else if(eval("\x01") == 218)
         {
            set("\x01",eval("\x01") + 138);
            if(§§pop())
            {
               set("\x01",eval("\x01") + 454);
            }
         }
         else if(eval("\x01") == 807)
         {
            set("\x01",eval("\x01") + 73);
            §§push(true);
         }
         else if(eval("\x01") == 43)
         {
            set("\x01",eval("\x01") + 853);
            if(§§pop())
            {
               set("\x01",eval("\x01") - 745);
            }
         }
         else if(eval("\x01") == 786)
         {
            set("\x01",eval("\x01") - 623);
            if(§§pop())
            {
               set("\x01",eval("\x01") + 145);
            }
         }
         else
         {
            if(eval("\x01") == 919)
            {
               set("\x01",eval("\x01") - 775);
               break;
            }
            if(eval("\x01") == 546)
            {
               set("\x01",eval("\x01") + 285);
               break;
            }
            if(eval("\x01") == 142)
            {
               set("\x01",eval("\x01") + 804);
               §§push(§§pop()(§§pop()));
               break;
            }
            if(eval("\x01") == 896)
            {
               set("\x01",eval("\x01") - 745);
               break;
            }
            if(eval("\x01") == 645)
            {
               set("\x01",eval("\x01") - 441);
               §§push(true);
            }
            else
            {
               if(eval("\x01") == 373)
               {
                  set("\x01",eval("\x01") + 434);
                  break;
               }
               if(eval("\x01") == 880)
               {
                  set("\x01",eval("\x01") - 223);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") - 214);
                  }
               }
               else if(eval("\x01") == 308)
               {
                  set("\x01",eval("\x01") + 524);
                  §§push(true);
               }
               else if(eval("\x01") == 810)
               {
                  set("\x01",eval("\x01") - 463);
               }
               else if(eval("\x01") == 832)
               {
                  set("\x01",eval("\x01") - 690);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") + 804);
                  }
               }
               else if(eval("\x01") == 390)
               {
                  set("\x01",eval("\x01") + 529);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") - 775);
                  }
               }
               else if(eval("\x01") == 204)
               {
                  set("\x01",eval("\x01") + 169);
                  if(§§pop())
                  {
                     set("\x01",eval("\x01") + 434);
                  }
               }
               else
               {
                  if(eval("\x01") != 443)
                  {
                     if(eval("\x01") == 347)
                     {
                        set("\x01",eval("\x01") + 570);
                        introbgm = new Sound(this);
                        introbgm.attachSound("intro");
                        introbgm.start(0,1);
                        gamehelp_mc._visible = false;
                        gamehelp_mc.stop();
                        start_btn.onRelease = function()
                        {
                           introbgm.stop();
                           gotoAndStop(2);
                        };
                        help_btn.onRelease = function()
                        {
                           if(!gamehelp_mc._visible)
                           {
                              gamehelp_mc._visible = true;
                              gamehelp_mc.play();
                           }
                        };
                        stop();
                        gamehelp_mc._visible = false;
                        gamehelp_mc.stop();
                        start_btn.onRelease = function()
                        {
                           gotoAndStop(2);
                        };
                        help_btn.onRelease = function()
                        {
                           if(!gamehelp_mc._visible)
                           {
                              gamehelp_mc._visible = true;
                              gamehelp_mc.play();
                           }
                        };
                        if(ServerConnection.getRankEnabled())
                        {
                           rank_btn.onRelease = function()
                           {
                              ServerConnection.onGameRankRequest();
                           };
                        }
                        else
                        {
                           rank_btn._visible = false;
                        }
                        stop();
                        break;
                     }
                     if(eval("\x01") == 917)
                     {
                        set("\x01",eval("\x01") - 917);
                     }
                     break;
                  }
                  set("\x01",eval("\x01") - 225);
                  §§push(true);
               }
            }
         }
      }
   }
}
