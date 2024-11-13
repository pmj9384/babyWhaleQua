var §\x01§ = 289;
while(true)
{
   if(eval("\x01") == 289)
   {
      set("\x01",eval("\x01") + 185);
      §§push(true);
   }
   else if(eval("\x01") == 147)
   {
      set("\x01",eval("\x01") + 103);
      §§push(true);
   }
   else if(eval("\x01") == 474)
   {
      set("\x01",eval("\x01") + 247);
      if(§§pop())
      {
         set("\x01",eval("\x01") - 574);
      }
   }
   else
   {
      if(eval("\x01") == 721)
      {
         set("\x01",eval("\x01") - 574);
         break;
      }
      if(eval("\x01") == 250)
      {
         set("\x01",eval("\x01") - 221);
         if(§§pop())
         {
            set("\x01",eval("\x01") + 441);
         }
      }
      else
      {
         if(eval("\x01") == 29)
         {
            set("\x01",eval("\x01") + 441);
            break;
         }
         if(eval("\x01") != 470)
         {
            if(eval("\x01") == 876)
            {
               set("\x01",eval("\x01") - 530);
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
               if(!_global.nhn.game.DigitSet)
               {
                  var _loc2_ = nhn.game.DigitSet = function(mc)
                  {
                     this.base_mc = mc;
                     this.arranged = false;
                     this.figure = "0";
                     this.digits_array = new Array();
                  }.prototype;
                  _loc2_.__set__number = function(v)
                  {
                     if(!this.arranged)
                     {
                        this.arrange();
                     }
                     this.figure = String(v);
                     var _loc3_ = this.digits_array.length;
                     var _loc2_ = 0;
                     while(_loc2_ < _loc3_)
                     {
                        if(_loc2_ < this.figure.length)
                        {
                           this.digits_array[_loc2_].number = this.numberAt(_loc2_);
                           this.digits_array[_loc2_].visible = true;
                        }
                        else
                        {
                           this.digits_array[_loc2_].number = 0;
                           this.digits_array[_loc2_].visible = false;
                        }
                        _loc2_ = _loc2_ + 1;
                     }
                     this.applyAlign(this.figure.length);
                     return this.number;
                  };
                  _loc2_.applyAlign = function(length)
                  {
                     if(this.align == "center")
                     {
                        var _loc3_ = this.width / (this.digits_array.length - 1);
                        var _loc4_ = (this.left + this.right) / 2 - (length - 1) * _loc3_ / 2;
                        var _loc2_ = 0;
                        while(_loc2_ < length)
                        {
                           this.digits_array[_loc2_]._x = _loc4_ + _loc2_ * _loc3_;
                           _loc2_ = _loc2_ + 1;
                        }
                     }
                  };
                  _loc2_.__get__number = function()
                  {
                     return Number(this.figure);
                  };
                  _loc2_.registerDigit = function(dg)
                  {
                     this.digits_array.push(dg);
                     this.arranged = false;
                  };
                  _loc2_.numberAt = function(i)
                  {
                     return Number(this.figure.charAt(this.figure.length - i - 1));
                  };
                  _loc2_.arrange = function()
                  {
                     var _loc4_ = this.digits_array;
                     var _loc7_ = _loc4_.length;
                     var _loc5_ = undefined;
                     var _loc6_ = undefined;
                     var _loc8_ = undefined;
                     var _loc3_ = 0;
                     while(_loc3_ < _loc7_)
                     {
                        var _loc2_ = _loc3_;
                        while(_loc2_ < _loc7_)
                        {
                           _loc5_ = _loc4_[_loc3_];
                           _loc6_ = _loc4_[_loc2_];
                           if(_loc5_.before(_loc6_))
                           {
                              _loc8_ = _loc5_;
                              _loc4_[_loc3_] = _loc6_;
                              _loc4_[_loc2_] = _loc5_;
                           }
                           _loc2_ = _loc2_ + 1;
                        }
                        _loc3_ = _loc3_ + 1;
                     }
                     this.right = _loc4_[_loc4_.length - 1]._x;
                     this.left = _loc4_[0]._x;
                     this.width = this.right - this.left;
                     this.arranged = true;
                  };
                  nhn.game.DigitSet = function(mc)
                  {
                     this.base_mc = mc;
                     this.arranged = false;
                     this.figure = "0";
                     this.digits_array = new Array();
                  }.digitsets = new Object();
                  §§push(_loc2_.addProperty("number",_loc2_.__get__number,_loc2_.__set__number));
                  §§push(ASSetPropFlags(nhn.game.DigitSet.prototype,null,1));
               }
               §§pop();
               break;
            }
            if(eval("\x01") == 346)
            {
               set("\x01",eval("\x01") - 346);
            }
            break;
         }
         set("\x01",eval("\x01") + 406);
      }
   }
}
