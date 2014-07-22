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
    {$if defined (_M_protoInkLLs_09v2__var_FIRST)}
        {$define _var_piLLs09v2_FIRST:=_M_protoInkLLs_09v2__var_FIRST}
    {$else}
        {$FATAL 'macro ".._var_piLLs09v2_FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_09v2__cst_LIST)}
        {$define _cst_piLLs09v2_LIST:=_M_protoInkLLs_09v2__cst_LIST}
    {$else}
        {$FATAL 'macro ".._cst_piLLs09v2_LIST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_09v2__out_COUNT)}
        {$define _tmp_piLLs09v2_COUNT:=_M_protoInkLLs_09v2__out_COUNT}
    {$else}
        {$FATAL 'macro ".._tmp_piLLs09v2_COUNT" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_09v2__lcl_getNext)}
        {$define _fnc_piLLs09v2_getNext:=_M_protoInkLLs_09v2__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLs09v2_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_09v2__lcl_setNext)}
        {$define _prc_piLLs09v2_setNext:=_M_protoInkLLs_09v2__lcl_setNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__SetNext)}
        {$define _prc_piLLs09v2_setNext:=_M_protoInkLLs_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
{%region /fold 'setUP local vars'                                        }
{$if defined (_m_protoInkLLs_09v2__tmp_POINTER)}
    {$define _tmp_piLLs09v2_POINTER:=_m_protoInkLLs_09v2__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piLLs09v2_POINTER:=tmp}
{$endif}
//---
{$if defined (_m_protoInkLLs_09v2__tmp_COUNT)}
    {$define _tmp_piLLs09v2_COUNT:=_m_protoInkLLs_09v2__tmp_COUNT}
{$else}
var tmc:tInkLLNodeCount;
    {$define _tmp_piLLs09v2_COUNT:=tmc}
{$endif}
{%endregion 'setUP local vars' /fold}
begin
    if _var_piLLs09v2_FIRST<>nil then begin
        //--- вспомогательный алгоритм
        {$ifDef inkLLsimple_fncHeadMessage}{$message 'inline #1 -> protoInkLLs_bodyFNC_05v2__getLast'}{$endIF}
            {$deFine _M_protoInkLLs_05v2__cst_FIRST:=_var_piLLs09v2_FIRST}
            {$deFine _M_protoInkLLs_05v2__out_COUNT:=_M_protoInkLLs_09v2__out_COUNT}
            {$deFine _M_protoInkLLs_05v2__out_LAST :=_tmp_piLLs09v2_POINTER}
            {$I protoInkLLs_bodyFNC_05v2__getLast.inc}
        //--- основной алгоритм
        {$ifDef inkLLsimple_fncHeadMessage}{$message 'MAIN code'}{$endIF}
       _prc_piLLs09v2_setNext(_tmp_piLLs09v2_POINTER,_cst_piLLs09v2_LIST);
    end
    else begin
       _var_piLLs09v2_FIRST:=_cst_piLLs09v2_LIST;
       _M_protoInkLLs_09v2__out_COUNT:=0;
    end;
    //-- теперь дасчитаем кол-во
    {$ifDef inkLLsimple_fncHeadMessage}{$message 'inline #2 -> protoInkLLs_bodyFNC_05v2__getLast'}{$endIF}
        {$deFine _M_protoInkLLs_05v2__cst_FIRST:=_cst_piLLs09v2_LIST}
        {$deFine _M_protoInkLLs_05v2__out_COUNT:=_tmp_piLLs09v2_COUNT}
        {$deFine _M_protoInkLLs_05v2__out_LAST :=_tmp_piLLs09v2_POINTER}
        {$I protoInkLLs_bodyFNC_05v2__getLast.inc}
   _M_protoInkLLs_09v2__out_COUNT:=_M_protoInkLLs_09v2__out_COUNT+_tmp_piLLs09v2_COUNT;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef SupreLocal macros
    {$unDef _tmp_piLLs09v2_POINTER}
    {$unDef _tmp_piLLs09v2_COUNT}
    //--- undef SupreLocal macros
    {$unDef _var_piLLs09v2_FIRST}
    {$unDef _cst_piLLs09v2_LIST}
    {$unDef _tmp_piLLs09v2_COUNT}
    {$unDef _fnc_piLLs09v2_getNext}
    {$unDef _prc_piLLs09v2_setNext}
    //--- undef user
    {$unDef _m_protoInkLLs_09v2__tmp_POINTER}
    {$unDef _m_protoInkLLs_09v2__tmp_COUNT}
    {$unDef _M_protoInkLLs_09v2__var_FIRST}
    {$unDef _M_protoInkLLs_09v2__cst_LIST}
    {$unDef _M_protoInkLLs_09v2__out_COUNT}
    {$unDef _M_protoInkLLs_09v2__lcl_getNext}
    {$unDef _M_protoInkLLs_09v2__lcl_setNext}
{%endregion 'unDEF used macros' /fold}

