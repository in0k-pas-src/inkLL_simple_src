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
    {$if defined (_M_protoInkLLs_69__var_FIRST)}
        {$define _var_piLLs69_FIRST:=_M_protoInkLLs_69__var_FIRST}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkLLs_69__lcl_getNext)}
        {$define _fnc_piLLs69_getNext:=_M_protoInkLLs_69__lcl_getNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__GetNext)}
        {$define _fnc_piLLs69_getNext:=_M_protoInkLLs_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkLLs_69__lcl_setNext)}
        {$define _prc_piLLs69_setNext:=_M_protoInkLLs_69__lcl_setNext}
    {$elseif defined (_M_protoInkLLs_blockFNK__SetNext)}
        {$define _prc_piLLs69_setNext:=_M_protoInkLLs_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
{%region /fold 'setUP local VARs'                                        }
{$if defined (_m_protoInkLLs_69__tmp_POINTER_01)}
    {$define _tmp_piLLs69_P01:=_m_protoInkLLs_69__tmp_POINTER_01}
{$else}
var tmp:pointer;
    {$define _tmp_piLLs69_P01:=tmp}
{$endif}
//---
{$if defined (_m_protoInkLLs_69__tmp_POINTER_02)}
    {$define _tmp_piLLs69_P02:=_m_protoInkLLs_69__tmp_POINTER_02}
{$else}
var tmq:pointer;
    {$define _tmp_piLLs69_P02:=tmq}
{$endif}
{%endregion}
begin
    if (_var_piLLs69_FIRST<>nil)and              //< он вообще есть
       (_fnc_piLLs69_getNext(_var_piLLs69_FIRST)<>nil) //< есть еще хотяб один
    then begin
       _tmp_piLLs69_P01  :=_var_piLLs69_FIRST;
       _var_piLLs69_FIRST:=nil;
        while _tmp_piLLs69_P01<>nil do begin
           _tmp_piLLs69_P02  :=_fnc_piLLs69_getNext(_tmp_piLLs69_P01);
           _prc_piLLs69_setNext(_tmp_piLLs69_P01,_var_piLLs69_FIRST);
           _var_piLLs69_FIRST:=_tmp_piLLs69_P01;
           _tmp_piLLs69_P01  :=_tmp_piLLs69_P02;
        end;
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Supre Local
    {$unDef _tmp_piLLs69_P01}
    {$unDef _tmp_piLLs69_P02}
    //--- undef Local macros
    {$unDef _var_piLLs69_FIRST}
    {$unDef _fnc_piLLs69_getNext}
    {$unDef _prc_piLLs69_setNext}
    //--- undef user
    {$undef _m_protoInkLLs_69__tmp_POINTER_01}
    {$undef _m_protoInkLLs_69__tmp_POINTER_02}
    {$undef _M_protoInkLLs_69__var_FIRST}
    {$unDef _M_protoInkLLs_69__lcl_getNext}
    {$unDef _M_protoInkLLs_69__lcl_setNext}
{%endregion 'unDEF used macros' /fold}

