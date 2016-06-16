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
    {$if defined (_M_protoInkLLs_C0v1__var_FIRST)}
        {$define _var_piLLsC0v1_FIRST:=_M_protoInkLLs_C0v1__var_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_C0v1__cst_NODE)}
        {$define _cst_piLLsC0v1_NODE:=_M_protoInkLLs_C0v1__cst_NODE}
    {$else}
        {$FATAL 'macro ".._NODE" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_C0v1__lcl_getNext)}
        {$define _fnc_piLLsC0v1_getNext:=_M_protoInkLLs_C0v1__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLsC0v1_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_C0v1__lcl_setNext)}
        {$define _prc_piLLsC0v1_setNext:=_M_protoInkLLs_C0v1__lcl_setNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__SetNext)}
        {$define _prc_piLLsC0v1_setNext:=_M_protoInkLLs_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
{%region /fold 'setUP local vars'                                        }
{$if defined (_m_protoInkLLs_C0v1__tmp_POINTER)}
    {$define _tmp_piLLsC0v1_POINTER:=_m_protoInkLLs_C0v1__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piLLsC0v1_POINTER:=tmp}
{$endif}
{%endregion 'setUP local vars' /fold}
begin
    //-- проверки
    {$ifOpt D+}
        if _cst_piLLsC0v1_NODE=nil then begin
            raise Exception.CReate('_cst_piLLsC0v1_NODE==nil !!!');
        end;
    {$endif}
    //-- агоритм-ритм-ритм
    if _var_piLLsC0v1_FIRST<>nil then begin //< имеет ли смысл работать
        if _cst_piLLsC0v1_NODE<>_var_piLLsC0v1_FIRST //< такая ситуация должна быть чаще
        then begin //< мда, надо искать предыдущий
            _tmp_piLLsC0v1_POINTER:=_var_piLLsC0v1_FIRST;
             while (_tmp_piLLsC0v1_POINTER<>nil)and(_fnc_piLLsC0v1_getNext(_tmp_piLLsC0v1_POINTER)<>_cst_piLLsC0v1_NODE)
             do _tmp_piLLsC0v1_POINTER:=_fnc_piLLsC0v1_getNext(_tmp_piLLsC0v1_POINTER);
             // и вырезаем из него
             if _tmp_piLLsC0v1_POINTER<>nil then begin //< всетаки вырезаем
                _prc_piLLsC0v1_setNext(_tmp_piLLsC0v1_POINTER, _fnc_piLLsC0v1_getNext(_cst_piLLsC0v1_NODE));
             end;
        end
        else _var_piLLsC0v1_FIRST:=_fnc_piLLsC0v1_getNext(_cst_piLLsC0v1_NODE) //<это был первый элемент, его и вырезаем
    end
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Supre Local macros
    {$unDef _tmp_piLLsC0v1_POINTER}
    //--- undef Local macros
    {$unDef _var_piLLsC0v1_FIRST}
    {$unDef _cst_piLLsC0v1_NODE}
    {$unDef _fnc_piLLsC0v1_getNext}
    {$unDef _prc_piLLsC0v1_setNext}
    //--- undef user
    {$unDef _m_protoInkLLs_C0v1__tmp_POINTER}
    {$unDef _M_protoInkLLs_C0v1__var_FIRST}
    {$unDef _M_protoInkLLs_C0v1__cst_NODE}
    {$unDef _M_protoInkLLs_C0v1__lcl_getNext}
    {$unDef _M_protoInkLLs_C0v1__lcl_setNext}
{%endregion 'unDEF used macros' /fold}
