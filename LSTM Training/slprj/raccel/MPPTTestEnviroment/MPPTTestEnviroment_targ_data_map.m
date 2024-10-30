    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 49;
            section.data(49)  = dumData; %prealloc

                    ;% rtP.PVArray_Npar
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.uib1_Gain
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Constant_Value
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.UnitDelay_InitialCondition
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.fromWS_Signal1_Time0
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.fromWS_Signal1_Data0
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 304;

                    ;% rtP.FromWorkspace_Time0
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 604;

                    ;% rtP.FromWorkspace_Data0
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 905;

                    ;% rtP.FromWorkspace1_Time0
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 1206;

                    ;% rtP.FromWorkspace1_Data0
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 1507;

                    ;% rtP.FromWorkspace2_Time0
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 1808;

                    ;% rtP.FromWorkspace2_Data0
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 2109;

                    ;% rtP.FromWorkspace3_Time0
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 2410;

                    ;% rtP.FromWorkspace3_Data0
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 2711;

                    ;% rtP.FromWorkspace4_Time0
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 3012;

                    ;% rtP.FromWorkspace4_Data0
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 3313;

                    ;% rtP.uSref_Gain
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 3614;

                    ;% rtP.StateSpace_AS_param
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 3615;

                    ;% rtP.StateSpace_BS_param
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 3631;

                    ;% rtP.StateSpace_CS_param
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 3651;

                    ;% rtP.StateSpace_DS_param
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 3675;

                    ;% rtP.StateSpace_X0_param
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 3705;

                    ;% rtP.donotdeletethisgain_Gain
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 3709;

                    ;% rtP.donotdeletethisgain_Gain_o2ediqignj
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 3710;

                    ;% rtP.donotdeletethisgain_Gain_a3rouvps5o
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 3711;

                    ;% rtP.donotdeletethisgain_Gain_g2mnwthege
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 3712;

                    ;% rtP.Constant3_Value
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 3713;

                    ;% rtP.Constant2_Value
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 3714;

                    ;% rtP.SwitchCurrents_Value
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 3715;

                    ;% rtP.AvgVoltage_Value
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 3717;

                    ;% rtP.u_K_Value
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 3718;

                    ;% rtP.Temperature_Value
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 3719;

                    ;% rtP.Tref_K_Value
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 3720;

                    ;% rtP.alpha_Isc_Gain
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 3721;

                    ;% rtP.IL_module_Value
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 3722;

                    ;% rtP.Rs_array_Value
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 3723;

                    ;% rtP.one1_Value
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 3724;

                    ;% rtP.Tref_K1_Value
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 3725;

                    ;% rtP.dEgdT_Gain
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 3726;

                    ;% rtP.EgRef_Gain
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 3727;

                    ;% rtP.Tref_K2_Value
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 3728;

                    ;% rtP.I0_array_Gain
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 3729;

                    ;% rtP.EgRef_Value
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 3730;

                    ;% rtP.k1_Gain
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 3731;

                    ;% rtP.Rsh_array_Value
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 3732;

                    ;% rtP.Rsh_array_5Sref_Value
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 3733;

                    ;% rtP.VT_ref_array_Gain
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 3734;

                    ;% rtP.one_Value
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 3735;

                    ;% rtP.eee_Value
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 3736;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% rtP.u_CurrentSetting
                    section.data(1).logicalSrcIdx = 49;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.u_CurrentSetting_hs31nmoa3a
                    section.data(2).logicalSrcIdx = 50;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.u_CurrentSetting_ir0jkhjpr4
                    section.data(3).logicalSrcIdx = 51;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.u_CurrentSetting_o4g41xxlfn
                    section.data(4).logicalSrcIdx = 52;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.u_CurrentSetting_khaqidsf01
                    section.data(5).logicalSrcIdx = 53;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.u_CurrentSetting_m1x0003fvm
                    section.data(6).logicalSrcIdx = 54;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.u_CurrentSetting_fz0kzbgp5d
                    section.data(7).logicalSrcIdx = 55;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.u_CurrentSetting_na1jc0pnhw
                    section.data(8).logicalSrcIdx = 56;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.u_CurrentSetting_e1l1w3mxse
                    section.data(9).logicalSrcIdx = 57;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.u_CurrentSetting_difsidxqko
                    section.data(10).logicalSrcIdx = 58;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.u_CurrentSetting_ojtqhpabmt
                    section.data(11).logicalSrcIdx = 59;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

                    ;% rtB.akyt3lfkwh
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.njil4ymwjf
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.h0wrsbi0st
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.ofammli3u4
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 8;

                    ;% rtB.jup34gd1or
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 10;

                    ;% rtB.j1iluh4g4l
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 11;

                    ;% rtB.o02cr54nvq
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 12;

                    ;% rtB.aemiuyfzah
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 13;

                    ;% rtB.pu0pww30s5
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 14;

                    ;% rtB.ampgfa5hq1
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 15;

                    ;% rtB.c3wmwmevlm
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 16;

                    ;% rtB.bf0othlvxv
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 17;

                    ;% rtB.abocamivf3
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 18;

                    ;% rtB.lkf3m54okc
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 19;

                    ;% rtB.pd05mevuny
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 20;

                    ;% rtB.kpvk44fokn
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 21;

                    ;% rtB.lzs1gqogb3
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 22;

                    ;% rtB.bq01lft3hq
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 23;

                    ;% rtB.g1elq1ywpj
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 24;

                    ;% rtB.c3maug3nzc
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 25;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.exeralr4po
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.g5ufooow0i
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtDW.jqrqq3twqe.TimePtr
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.j4uq2hdcjm.TimePtr
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.lazvpzocdc.TimePtr
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.fw1yld0fsl.TimePtr
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.ayxv0vieza.TimePtr
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.mkqcya2tld.TimePtr
                    section.data(6).logicalSrcIdx = 7;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.mzxjwgc5lv.AS
                    section.data(7).logicalSrcIdx = 8;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.kp0ygpbt3q.LoggedData
                    section.data(8).logicalSrcIdx = 9;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% rtDW.h1nceqotqd.PrevIndex
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.cvaln4lwyx.PrevIndex
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.axcms0d2td.PrevIndex
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.h41wiesuir.PrevIndex
                    section.data(4).logicalSrcIdx = 13;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.h1ghxcbm2k.PrevIndex
                    section.data(5).logicalSrcIdx = 14;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.of2fqrjlsu.PrevIndex
                    section.data(6).logicalSrcIdx = 15;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.a5z1oau2kb
                    section.data(7).logicalSrcIdx = 16;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3395661662;
    targMap.checksum1 = 2450273611;
    targMap.checksum2 = 3863357328;
    targMap.checksum3 = 2479319912;

