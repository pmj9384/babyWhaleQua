var §\x01§ = 459;
while(true)
{
   if(eval("\x01") == 459)
   {
      set("\x01",eval("\x01") + 325);
      §§push(true);
   }
   else
   {
      if(eval("\x01") == 971)
      {
         set("\x01",eval("\x01") - 646);
         nextFrame();
         break;
      }
      if(eval("\x01") == 33)
      {
         set("\x01",eval("\x01") + 938);
         if(§§pop())
         {
            set("\x01",eval("\x01") - 646);
         }
      }
      else if(eval("\x01") == 325)
      {
         set("\x01",eval("\x01") + 327);
      }
      else if(eval("\x01") == 777)
      {
         set("\x01",eval("\x01") - 744);
         §§push(true);
      }
      else if(eval("\x01") == 784)
      {
         set("\x01",eval("\x01") + 108);
         if(§§pop())
         {
            set("\x01",eval("\x01") - 292);
         }
      }
      else
      {
         if(eval("\x01") == 982)
         {
            set("\x01",eval("\x01") - 205);
            duplicateMovieClip(§§pop(),§§pop(),§§pop());
            break;
         }
         if(eval("\x01") == 652)
         {
            set("\x01",eval("\x01") - 242);
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
            if(!_global.nhn.game.SoundMaster)
            {
               var _loc2_ = nhn.game.SoundMaster = function(mc, b, n)
               {
                  this.base_mc = mc;
                  this.base = b;
                  this.sound_array = new Array(n);
                  this.initclip = false;
                  if(n > 0)
                  {
                     this.createAllSound(n);
                  }
               }.prototype;
               _loc2_.createAllSound = function(n)
               {
                  var _loc3_ = undefined;
                  var _loc2_ = 0;
                  while(_loc2_ < n)
                  {
                     _loc3_ = this.base_mc.createEmptyMovieClip("_soundmaster" + (this.base + _loc2_),this.base + _loc2_);
                     this.sound_array[_loc2_] = new Sound(_loc3_);
                     this.sound_array[_loc2_].mc = _loc3_;
                     _loc2_ = _loc2_ + 1;
                  }
                  this.initclip = true;
               };
               _loc2_.attachAllSound = function()
               {
                  if(!this.initclip)
                  {
                     this.createAllSound(arguments.length);
                  }
                  var _loc3_ = 0;
                  while(_loc3_ < arguments.length)
                  {
                     this.sound_array[_loc3_].attachSound(arguments[_loc3_]);
                     this.volume_set[_loc3_] = 100;
                     _loc3_ = _loc3_ + 1;
                  }
               };
               _loc2_.setAllVolume = function()
               {
                  var _loc3_ = 0;
                  while(_loc3_ < arguments.length)
                  {
                     this.sound_array[_loc3_].setVolume(arguments[_loc3_]);
                     this.volume_set[_loc3_] = arguments[_loc3_];
                     _loc3_ = _loc3_ + 1;
                  }
               };
               _loc2_.sound_off = function()
               {
                  var _loc2_ = 0;
                  while(_loc2_ < this.volume_set.length)
                  {
                     this.sound_array[_loc2_].setVolume(0);
                     _loc2_ = _loc2_ + 1;
                  }
               };
               _loc2_.sound_on = function()
               {
                  var _loc2_ = 0;
                  while(_loc2_ < this.volume_set.length)
                  {
                     this.sound_array[_loc2_].setVolume(this.volume_set[_loc2_]);
                     _loc2_ = _loc2_ + 1;
                  }
               };
               _loc2_.setAllPan = function()
               {
                  var _loc3_ = 0;
                  while(_loc3_ < arguments.length)
                  {
                     this.sound_array[_loc3_].setPan(arguments[_loc3_]);
                     _loc3_ = _loc3_ + 1;
                  }
               };
               _loc2_.setVolume = function(n, vol, register)
               {
                  var _loc3_ = this.sound_array[n];
                  if(vol != undefined)
                  {
                     _loc3_.setVolume(vol);
                  }
                  if(register != undefined)
                  {
                     this.volume_set[n] = vol;
                  }
               };
               _loc2_.setPan = function(n, pan)
               {
                  var _loc2_ = this.sound_array[n];
                  if(pan != undefined)
                  {
                     _loc2_.setPan(pan);
                  }
               };
               _loc2_.start = function(n, offset, loop, vol, pan)
               {
                  var _loc2_ = this.sound_array[n];
                  if(vol > 0)
                  {
                     _loc2_.setVolume(vol);
                     if(pan != undefined)
                     {
                        _loc2_.setPan(pan);
                     }
                  }
                  _loc2_.start(offset,loop);
               };
               _loc2_.stop = function(n)
               {
                  this.sound_array[n].stop();
               };
               _loc2_.stopAllSounds = function()
               {
                  var _loc2_ = 0;
                  while(_loc2_ < this.sound_array.length)
                  {
                     this.sound_array[_loc2_].stop();
                     _loc2_ = _loc2_ + 1;
                  }
               };
               _loc2_.toString = function()
               {
                  return "[SoundMaster]";
               };
               _loc2_.volume_set = [];
               §§push(ASSetPropFlags(nhn.game.SoundMaster.prototype,null,1));
            }
            §§pop();
            break;
         }
         if(eval("\x01") == 410)
         {
            set("\x01",eval("\x01") - 410);
            break;
         }
         if(eval("\x01") == 892)
         {
            set("\x01",eval("\x01") - 292);
            break;
         }
         if(eval("\x01") == 19)
         {
            set("\x01",eval("\x01") + 963);
            if(§§pop())
            {
               set("\x01",eval("\x01") - 205);
            }
         }
         else
         {
            if(eval("\x01") != 600)
            {
               break;
            }
            set("\x01",eval("\x01") - 581);
            §§push(true);
         }
      }
   }
}
