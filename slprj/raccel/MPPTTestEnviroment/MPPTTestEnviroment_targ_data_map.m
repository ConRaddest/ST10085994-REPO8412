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
            section.nData     = 69;
            section.data(69)  = dumData; %prealloc

                    ;% rtP.PVArray_Npar
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.mapminmax_xmax
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.mapminmax_reverse_xmax
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3;

                    ;% rtP.mapminmax_xmin
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% rtP.mapminmax_reverse_xmin
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% rtP.mapminmax_ymax
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 7;

                    ;% rtP.mapminmax_reverse_ymax
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 8;

                    ;% rtP.mapminmax_ymin
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 9;

                    ;% rtP.mapminmax_reverse_ymin
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 10;

                    ;% rtP.uib1_Gain
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 11;

                    ;% rtP.Constant_Value
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 12;

                    ;% rtP.UnitDelay_InitialCondition
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 13;

                    ;% rtP.fromWS_Signal1_Time0
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 14;

                    ;% rtP.fromWS_Signal1_Data0
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 314;

                    ;% rtP.FromWorkspace_Time0
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 614;

                    ;% rtP.FromWorkspace_Data0
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 915;

                    ;% rtP.FromWorkspace1_Time0
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 1216;

                    ;% rtP.FromWorkspace1_Data0
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 1517;

                    ;% rtP.uSref_Gain
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 1818;

                    ;% rtP.StateSpace_AS_param
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 1819;

                    ;% rtP.StateSpace_BS_param
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 1835;

                    ;% rtP.StateSpace_CS_param
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 1855;

                    ;% rtP.StateSpace_DS_param
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 1879;

                    ;% rtP.StateSpace_X0_param
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 1909;

                    ;% rtP.donotdeletethisgain_Gain
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 1913;

                    ;% rtP.Gain_Gain
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 1914;

                    ;% rtP.Gain1_Gain
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 1915;

                    ;% rtP.Saturation_UpperSat
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 1916;

                    ;% rtP.Saturation_LowerSat
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 1917;

                    ;% rtP.Constant3_Value
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 1918;

                    ;% rtP.Constant2_Value
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 1919;

                    ;% rtP.donotdeletethisgain_Gain_d1o5clwpjv
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 1920;

                    ;% rtP.donotdeletethisgain_Gain_a3rouvps5o
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 1921;

                    ;% rtP.donotdeletethisgain_Gain_g2mnwthege
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 1922;

                    ;% rtP.SwitchCurrents_Value
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 1923;

                    ;% rtP.IW111_Value
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 1925;

                    ;% rtP.IW1110_Value
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 1927;

                    ;% rtP.IW112_Value
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 1929;

                    ;% rtP.IW113_Value
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 1931;

                    ;% rtP.IW114_Value
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 1933;

                    ;% rtP.IW115_Value
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 1935;

                    ;% rtP.IW116_Value
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 1937;

                    ;% rtP.IW117_Value
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 1939;

                    ;% rtP.IW118_Value
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 1941;

                    ;% rtP.IW119_Value
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 1943;

                    ;% rtP.b1_Value
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 1945;

                    ;% rtP.one_Value
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 1955;

                    ;% rtP.one1_Value
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 1956;

                    ;% rtP.IW211_Value
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 1957;

                    ;% rtP.b2_Value
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 1967;

                    ;% rtP.u_K_Value
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 1968;

                    ;% rtP.Temperature_Value
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 1969;

                    ;% rtP.Tref_K_Value
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 1970;

                    ;% rtP.alpha_Isc_Gain
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 1971;

                    ;% rtP.IL_module_Value
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 1972;

                    ;% rtP.Rs_array_Value
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 1973;

                    ;% rtP.one1_Value_kceix1hyz1
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 1974;

                    ;% rtP.Tref_K1_Value
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 1975;

                    ;% rtP.dEgdT_Gain
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 1976;

                    ;% rtP.EgRef_Gain
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 1977;

                    ;% rtP.Tref_K2_Value
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 1978;

                    ;% rtP.I0_array_Gain
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 1979;

                    ;% rtP.EgRef_Value
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 1980;

                    ;% rtP.k1_Gain
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 1981;

                    ;% rtP.Rsh_array_Value
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 1982;

                    ;% rtP.Rsh_array_5Sref_Value
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 1983;

                    ;% rtP.VT_ref_array_Gain
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 1984;

                    ;% rtP.one_Value_irz0kd4ki2
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 1985;

                    ;% rtP.eee_Value
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 1986;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% rtP.u_CurrentSetting
                    section.data(1).logicalSrcIdx = 69;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.u_CurrentSetting_mybde2y4s0
                    section.data(2).logicalSrcIdx = 70;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.u_CurrentSetting_hs31nmoa3a
                    section.data(3).logicalSrcIdx = 71;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.u_CurrentSetting_o4g41xxlfn
                    section.data(4).logicalSrcIdx = 72;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.u_CurrentSetting_khaqidsf01
                    section.data(5).logicalSrcIdx = 73;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.u_CurrentSetting_m1x0003fvm
                    section.data(6).logicalSrcIdx = 74;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.u_CurrentSetting_fz0kzbgp5d
                    section.data(7).logicalSrcIdx = 75;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.u_CurrentSetting_na1jc0pnhw
                    section.data(8).logicalSrcIdx = 76;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.u_CurrentSetting_e1l1w3mxse
                    section.data(9).logicalSrcIdx = 77;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.u_CurrentSetting_ojtqhpabmt
                    section.data(10).logicalSrcIdx = 78;
                    section.data(10).dtTransOffset = 9;

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
            section.nData     = 17;
            section.data(17)  = dumData; %prealloc

                    ;% rtB.akyt3lfkwh
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.ddr3qqcafj
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.njil4ymwjf
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.h0wrsbi0st
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.ofammli3u4
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 9;

                    ;% rtB.j1iluh4g4l
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 11;

                    ;% rtB.csrrphvxwc
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 12;

                    ;% rtB.g40trl0ym0
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 13;

                    ;% rtB.abocamivf3
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 14;

                    ;% rtB.lkf3m54okc
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 15;

                    ;% rtB.pd05mevuny
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 16;

                    ;% rtB.kpvk44fokn
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 17;

                    ;% rtB.lzs1gqogb3
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 18;

                    ;% rtB.ezp5fomtbc
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 19;

                    ;% rtB.bq01lft3hq
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 20;

                    ;% rtB.g1elq1ywpj
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 21;

                    ;% rtB.c3maug3nzc
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 22;

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

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtDW.jqrqq3twqe.TimePtr
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.j4uq2hdcjm.TimePtr
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.lazvpzocdc.TimePtr
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.mzxjwgc5lv.AS
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.eekerhptxj.LoggedData
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.lklwansiy2.LoggedData
                    section.data(6).logicalSrcIdx = 7;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% rtDW.h1nceqotqd.PrevIndex
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.cvaln4lwyx.PrevIndex
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.axcms0d2td.PrevIndex
                    section.data(3).logicalSrcIdx = 10;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.a5z1oau2kb
                    section.data(4).logicalSrcIdx = 11;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.esoqq5ahh2
                    section.data(5).logicalSrcIdx = 12;
                    section.data(5).dtTransOffset = 14;

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


    targMap.checksum0 = 160205490;
    targMap.checksum1 = 299420185;
    targMap.checksum2 = 1323767297;
    targMap.checksum3 = 761063030;

