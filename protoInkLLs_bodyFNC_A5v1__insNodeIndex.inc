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
    {$if defined (_M_protoInkLLs_A5v1__var_FIRST)}
        {$define _var_piLLsA5v1_FIRST:=_M_protoInkLLs_A5v1__var_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_A5v1__var_INDEX)}
        {$define _var_piLLsA5v1_INDEX:=_M_protoInkLLs_A5v1__var_INDEX}
    {$else}
        {$FATAL 'macro ".._INDEX" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_A5v1__out_NODE)}
        {$define _out_piLLsA5v1_NODE:=_M_protoInkLLs_A5v1__out_NODE}
    {$else}
        {$FATAL 'macro ".._NODE" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_A5v1__lcl_getNext)}
        {$define _fnc_piLLsA5v1_getNext:=_M_protoInkLLs_A5v1__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLsA5v1_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_A5v1__lcl_setNext)}
        {$define _prc_piLLsA5v1_setNext:=_M_protoInkLLs_A5v1__lcl_setNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__SetNext)}
        {$define _prc_piLLsA5v1_setNext:=_M_protoInkLLs_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
{%endregion}
{%region /fold 'setUP local vars'                                        }
{$if defined (_m_protoInkLLs_A5v1__tmp_POINTER)}
    {$define _tmp_piLLsA5v1_POINTER:=_m_protoInkLLs_A5v1__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piLLsA5v1_POINTER:=tmp}
{$endif}
{%endregion}
begin
    //---
    if _var_piLLsA5v1_INDEX=0 then begin //< тут тупо ПЕРВЫй элемент вырезаем
        {$ifDef inkLLsimple_fncHeadMessage}{$message 'inline -> protoInkLLs_bodyFNC_C1__cutNodeFirst'}{$endIF}
        {$deFine _M_protoInkLLs_C1__var_FIRST:=_var_piLLsA5v1_FIRST}
        {$deFine _M_protoInkLLs_C1__out_NODE :=_out_piLLsA5v1_NODE}
        {$I protoInkLLs_bodyFNC_C1__cutNodeFirst.inc}
    end
    else begin //< очередь не пуста, и надо искать откуда вырезать
       _var_piLLsA5v1_INDEX:=_var_piLLsA5v1_INDEX-1; //< исчем узел ПЕРЕД вырезаемым
        {$ifDef inkLLsimple_fncHeadMessage}{$message 'inline -> protoInkLLs_bodyFNC_A1v2__getNodeOrLast'}{$endIF}
        {$deFine _M_protoInkLLs_A1v2__cst_FIRST:=_var_piLLsA5v1_FIRST}
        {$deFine _M_protoInkLLs_A1v2__var_Index:=_var_piLLsA5v1_INDEX}
        {$deFine _M_protoInkLLs_A1v2__out_NODE :=_tmp_piLLsA5v1_POINTER}
        {$I protoInkLLs_bodyFNC_A1v2__getNodeOrLast.inc}
        //-- и вырезаем
       _out_piLLsA5v1_NODE:=nil;
        if _tmp_piLLsA5v1_POINTER<>nil then begin
           _out_piLLsA5v1_NODE:=_fnc_piLLsA5v1_getNext(_tmp_piLLsA5v1_POINTER);
            if _out_piLLsA5v1_NODE<>nil
            then _prc_piLLsA5v1_setNext(_tmp_piLLsA5v1_POINTER,_fnc_piLLsA5v1_getNext(_out_piLLsA5v1_NODE));
        end
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Supre Local macros
    {$unDef _tmp_piLLsA5v1_POINTER}
    //--- undef Local macros
    {$unDef _var_piLLsA5v1_FIRST}
    {$unDef _var_piLLsA5v1_INDEX}
    {$unDef _out_piLLsA5v1_NODE}
    {$unDef _fnc_piLLsA5v1_getNext}
    {$unDef _prc_piLLsA5v1_setNext}
    //--- undef user
    {$unDef _m_protoInkLLs_A5v1__tmp_POINTER}
    {$unDef _M_protoInkLLs_A5v1__var_FIRST}
    {$unDef _M_protoInkLLs_A5v1__var_INDEX}
    {$unDef _M_protoInkLLs_A5v1__out_NODE}
    {$unDef _M_protoInkLLs_A5v1__lcl_getNext}
    {$unDef _M_protoInkLLs_A5v1__lcl_setNext}
{%endregion}

