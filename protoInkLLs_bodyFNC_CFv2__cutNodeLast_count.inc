{//.[ PRoTo Singly Linked Lists].....................[ in0k © 13.01.2013 ]...///
///                                                                          ///
///                                _____                                     ///
///                     +-+-+-+-+-|   __|_ _ first -> -                      ///
///                     |  PRoTo  |__   | | |         -                      ///
///                     +-+-+-+-+-|_____|_|_|         -                      ///
///                          v 2.0             nil <- =                      ///
///                                                                          ///
///............................................[ v 2.0 in0k © 27.05.2013 ]...//}
{%region /fold 'check "define" for all used macros'                      }
    //--- VARs
    {$if defined (_M_protoInkLLs_CFv2__var_FIRST)}
        {$define _var_piLLsCFv2_FIRST:=_M_protoInkLLs_CFv2__var_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_CFv2__out_COUNT)}
        {$define _out_piLLsCFv2_COUNT:=_M_protoInkLLs_CFv2__out_COUNT}
    {$else}
        {$FATAL 'macro "..2_COUNT" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_CFv2__out_LAST)}
        {$define _out_piLLsCFv2_LAST:=_M_protoInkLLs_CFv2__out_LAST}
    {$else}
        {$FATAL 'macro ".._LAST" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_CFv2__lcl_getNext)}
        {$define _fnc_piLLsCFv2_getNext:=_M_protoInkLLs_CFv2__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLsCFv2_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_CFv2__lcl_setNext)}
        {$define _prc_piLLsCFv2_setNext:=_M_protoInkLLs_CFv2__lcl_setNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__SetNext)}
        {$define _prc_piLLsCFv2_setNext:=_M_protoInkLLs_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
{%region /fold 'setUP local vars'                                        }
{$if defined (_m_protoInkLLs_CFv2__tmp_POINTER)}
    {$define _tmp_piLLsCFv2_POINTER:=_m_protoInkLLs_CFv2__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piLLsCFv2_POINTER:=tmp}
{$endif}
{%endregion 'setUP local vars' /fold}
begin
   _out_piLLsCFv2_LAST :=NIL;
   _out_piLLsCFv2_COUNT:=0;
   _tmp_piLLsCFv2_POINTER:=_var_piLLsCFv2_FIRST;
    //---
    if _fnc_piLLsCFv2_getNext(_tmp_piLLsCFv2_POINTER)<>nil then begin //< это не ЕДИНСТВЕННЫЙ
        // исчем ПЕРДпоследний, их тут как минимум ДВА
       _out_piLLsCFv2_COUNT:=1;
        while _fnc_piLLsCFv2_getNext(_fnc_piLLsCFv2_getNext(_tmp_piLLsCFv2_POINTER))<>nil do begin
           _tmp_piLLsCFv2_POINTER:=_fnc_piLLsCFv2_getNext(_tmp_piLLsCFv2_POINTER);
            inc(_out_piLLsCFv2_COUNT);
        end;
        //---
       _out_piLLsCFv2_LAST:=_fnc_piLLsCFv2_getNext(_tmp_piLLsCFv2_POINTER);
       _prc_piLLsCFv2_setNext(_tmp_piLLsCFv2_POINTER,NIL);
    end
    else begin //< он таки единственный был
      _out_piLLsCFv2_LAST :=_var_piLLsCFv2_FIRST;
      _var_piLLsCFv2_FIRST:=NIL;
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Supre Local macros
    {$unDef _tmp_piLLsCFv2_POINTER}
    //--- undef Local macros
    {$unDef _var_piLLsCFv2_FIRST}
    {$unDef _out_piLLsCFv2_COUNT}
    {$unDef _out_piLLsCFv2_LAST}
    {$unDef _fnc_piLLsCFv2_getNext}
    {$unDef _prc_piLLsCFv2_setNext}
    //--- undef user
    {$unDef _m_protoInkLLs_CFv2__tmp_POINTER}
    {$unDef _M_protoInkLLs_CFv2__var_FIRST}
    {$unDef _M_protoInkLLs_CFv2__out_COUNT}
    {$unDef _M_protoInkLLs_CFv2__out_LAST}
    {$unDef _M_protoInkLLs_CFv2__lcl_getNext}
    {$unDef _M_protoInkLLs_CFv2__lcl_setNext}
{%endregion 'unDEF used macros' /fold}

