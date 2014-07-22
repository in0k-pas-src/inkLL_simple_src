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
    {$if defined (_M_protoInkLLs_A3__var_FIRST)}
        {$define _var_piLLsA3_FIRST:=_M_protoInkLLs_A3__var_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_A3__var_INDEX)}
        {$define _var_piLLsA3_INDEX:=_M_protoInkLLs_A3__var_INDEX}
    {$else}
        {$FATAL 'macro ".._INDEX" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_A3__cst_NODE)}
        {$define _cst_piLLsA3_NODE:=_M_protoInkLLs_A3__cst_NODE}
    {$else}
        {$FATAL 'macro ".._NODE" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_A3__lcl_getNext)}
        {$define _fnc_piLLsA3_getNext:=_M_protoInkLLs_A3__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLsA3_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_A3__lcl_setNext)}
        {$define _prc_piLLsA3_setNext:=_M_protoInkLLs_A3__lcl_setNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__SetNext)}
        {$define _prc_piLLsA3_setNext:=_M_protoInkLLs_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
{%region /fold 'setUP local vars'                                        }
{$if defined (_m_protoInkLLs_A3__tmp_POINTER)}
    {$define _tmp_piLLsA3_POINTER:=_m_protoInkLLs_A3__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piLLsA3_POINTER:=tmp}
{$endif}
{%endregion 'setUP local vars' /fold}
begin
    //---
    if (_var_piLLsA3_FIRST=nil)or(_var_piLLsA3_INDEX=0) then begin //< тут тупо вставка ПЕРВЫМ элементом
        {$ifDef inkLLsimple_fncHeadMessage}{$message 'inline -> protoInkLLs_bodyFNC_06__insFirst'}{$endIF}
        {$deFine _M_protoInkLLs_06__var_FIRST:=_var_piLLsA3_FIRST}
        {$deFine _M_protoInkLLs_06__cst_NODE :=_cst_piLLsA3_NODE}
        {$I protoInkLLs_bodyFNC_06__insFirst.inc}
    end
    else begin //< очередь не пуста, и надо искать куда вставлять
       _var_piLLsA3_INDEX:=_var_piLLsA3_INDEX-1; //< надо найти ПРЕДидущий
        {$ifDef inkLLsimple_fncHeadMessage}{$message 'inline -> protoInkLLs_bodyFNC_A1v2__getNodeOrLast'}{$endIF}
        {$deFine _M_protoInkLLs_A1v2__cst_FIRST:=_var_piLLsA3_FIRST}
        {$deFine _M_protoInkLLs_A1v2__var_Index:=_var_piLLsA3_INDEX}
        {$deFine _M_protoInkLLs_A1v2__out_NODE :=_tmp_piLLsA3_POINTER}
        {$I 'protoInkLLs_bodyFNC_A1v2__getNodeOrLast.inc'}
        //-- и вставка
       _prc_piLLsA3_setNext(_cst_piLLsA3_NODE,_fnc_piLLsA3_getNext(_tmp_piLLsA3_POINTER));
       _prc_piLLsA3_setNext(_tmp_piLLsA3_POINTER,_cst_piLLsA3_NODE);
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Supre Local macros
    {$unDef _tmp_piLLsA3_POINTER}
    //--- undef Local macros
    {$unDef _var_piLLsA3_FIRST}
    {$unDef _var_piLLsA3_INDEX}
    {$unDef _cst_piLLsA3_NODE}
    {$unDef _fnc_piLLsA3_getNext}
    {$unDef _prc_piLLsA3_setNext}
    //--- undef user
    {$unDef _m_protoInkLLs_A3__tmp_POINTER}
    {$unDef _M_protoInkLLs_A3__var_FIRST}
    {$unDef _M_protoInkLLs_A3__var_INDEX}
    {$unDef _M_protoInkLLs_A3__cst_NODE}
    {$unDef _M_protoInkLLs_A3__lcl_getNext}
    {$unDef _M_protoInkLLs_A3__lcl_setNext}
{%endregion 'unDEF used macros' /fold}

