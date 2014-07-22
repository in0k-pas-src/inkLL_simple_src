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
    {$if defined (_M_protoInkLLs_E4__var_FIRST)}
        {$define _var_piLLsE4_FIRST:=_M_protoInkLLs_E4__var_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_E4__cst_cmpCTX)}
        {$define _cst_piLLsE4_cmpCXT:=_M_protoInkLLs_E4__cst_cmpCTX}
    {$else}
        {$FATAL 'macro ".._cmpCTX" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_E4__cst_cmpFNC)}
        {$define _cst_piLLsE4_cmpFNC:=_M_protoInkLLs_E4__cst_cmpFNC}
    {$else}
        {$FATAL 'macro ".._cmpFNC" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_E4__lcl_getNext)}
        {$define _fnc_piLLsE4_getNext:=_M_protoInkLLs_E4__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLsE4_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._GetNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_E4__lcl_setNext)}
        {$define _fnc_piLLsE4_setNext:=_M_protoInkLLs_E4__lcl_setNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__SetNext)}
        {$define _fnc_piLLsE4_setNext:=_M_protoInkLLs_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._GetNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_E4__lcl_dspPRC)}
        {$define _fnc_piLLsE4_dspPRC:=_M_protoInkLLs_E4__lcl_dspPRC}
    {$elseif defined (_M_protoInkLLs_blockFNK__nodeDST)}
        {$define _fnc_piLLsE4_dspPRC:=_M_protoInkLLs_blockFNK__nodeDST}
    {$else}
        {$FATAL 'macro ".._dspPRC" : NOT define!'}
    {$endif}
{%endregion}
{%region /fold 'setUP local VARs'                                        }
{$if defined (_m_protoInkLLs_E4__tmp_POINTER0)}
    {$define _tmp_piLLsE4_POINTER0:=_m_protoInkLLs_E4__tmp_POINTER0}
{$else}
var tmp:pointer;
    {$define _tmp_piLLsE4_POINTER0:=tmp}
{$endif}
{$if defined (_m_protoInkLLs_E4__tmp_POINTER1)}
    {$define _tmp_piLLsE4_POINTER1:=_m_protoInkLLs_E4__tmp_POINTER1}
{$else}
var tmq:pointer;
    {$define _tmp_piLLsE4_POINTER1:=tmq}
{$endif}
{%endregion}
begin
    //--- работа с ПЕРВЫМ элементом
    while (_var_piLLsE4_FIRST<>nil)and
          (_M_protoInkLLs_E4__cst_cmpFNC(_M_protoInkLLs_E4__cst_cmpCTX,_var_piLLsE4_FIRST))
    do begin
       // шаг на СЛЕДУЮЩИЙ
      _tmp_piLLsE4_POINTER0:=_var_piLLsE4_FIRST;
      _var_piLLsE4_FIRST  :=_fnc_piLLsE4_getNext(_tmp_piLLsE4_POINTER0);
       // уничтожение элемента tmp
      _fnc_piLLsE4_dspPRC(_tmp_piLLsE4_POINTER0);
    end;
    //--- работа с ПОСЛЕДУЮЩИМИ
    if _var_piLLsE4_FIRST<>nil then begin
       _tmp_piLLsE4_POINTER0:=_var_piLLsE4_FIRST;
       _tmp_piLLsE4_POINTER1:=_fnc_piLLsE4_getNext(_tmp_piLLsE4_POINTER0);
        while _tmp_piLLsE4_POINTER1<>nil do begin
            if _M_protoInkLLs_E4__cst_cmpFNC(_M_protoInkLLs_E4__cst_cmpCTX,_tmp_piLLsE4_POINTER1)
            then begin //< надо вырезать и уничтожить POINTER1
               _fnc_piLLsE4_setNext(_tmp_piLLsE4_POINTER0,_fnc_piLLsE4_getNext(_tmp_piLLsE4_POINTER1));
               _fnc_piLLsE4_dspPRC (_tmp_piLLsE4_POINTER1);
               _tmp_piLLsE4_POINTER1:=_fnc_piLLsE4_getNext(_tmp_piLLsE4_POINTER0);
            end
            else begin
               _tmp_piLLsE4_POINTER0:=_tmp_piLLsE4_POINTER1;
               _tmp_piLLsE4_POINTER1:=_fnc_piLLsE4_getNext(_tmp_piLLsE4_POINTER0);
            end;
        end;
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef SUPER local macros
    {$unDef _tmp_piLLsE4_POINTER0}
    {$unDef _tmp_piLLsE4_POINTER1}
    //--- undef Local macros
    {$unDef _var_piLLsE4_FIRST}
    {$unDef _cst_piLLsE4_cmpCXT}
    {$unDef _fnc_piLLsE4_cmpFNC}
    {$unDef _fnc_piLLsE4_dspPRC}
    {$unDef _fnc_piLLsE4_getNext}
    {$unDef _fnc_piLLsE4_setNext}
    //--- undef user macros
    {$undef _m_protoInkLLs_E4__tmp_POINTER0}
    {$undef _m_protoInkLLs_E4__tmp_POINTER1}
    {$undef _M_protoInkLLs_E4__var_FIRST}
    {$unDef _M_protoInkLLs_E4__cst_cmpCTX}
    {$unDef _M_protoInkLLs_E4__cst_cmpFNC}
    {$unDef _M_protoInkLLs_E4__lcl_dspPRC}
    {$unDef _M_protoInkLLs_E4__lcl_getNext}
    {$unDef _M_protoInkLLs_E4__lcl_setNext}
{%endregion}
