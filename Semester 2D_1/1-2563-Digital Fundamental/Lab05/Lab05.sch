<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="XLXN_12" />
        <signal name="XLXN_13" />
        <signal name="XLXN_14" />
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="XLXN_18" />
        <signal name="XLXN_19" />
        <signal name="XLXN_20" />
        <signal name="a_out" />
        <signal name="b_out" />
        <signal name="XLXN_23" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <signal name="c_out" />
        <signal name="XLXN_28" />
        <signal name="XLXN_29" />
        <signal name="XLXN_30" />
        <signal name="XLXN_31" />
        <signal name="XLXN_32" />
        <signal name="XLXN_33" />
        <signal name="XLXN_34" />
        <signal name="XLXN_35" />
        <signal name="XLXN_36" />
        <signal name="XLXN_38" />
        <signal name="XLXN_39" />
        <signal name="XLXN_40" />
        <signal name="XLXN_41" />
        <signal name="XLXN_42" />
        <signal name="XLXN_44" />
        <signal name="XLXN_45" />
        <signal name="XLXN_46" />
        <signal name="XLXN_47" />
        <signal name="XLXN_48" />
        <signal name="XLXN_49" />
        <signal name="XLXN_50" />
        <signal name="e_out" />
        <signal name="XLXN_52" />
        <signal name="XLXN_53" />
        <signal name="XLXN_54" />
        <signal name="XLXN_56" />
        <signal name="XLXN_57" />
        <signal name="XLXN_58" />
        <signal name="f_out" />
        <signal name="XLXN_60" />
        <signal name="XLXN_61" />
        <signal name="XLXN_62" />
        <signal name="XLXN_63" />
        <signal name="g_out" />
        <signal name="A" />
        <signal name="B" />
        <signal name="C" />
        <signal name="D" />
        <signal name="d_out" />
        <port polarity="Output" name="a_out" />
        <port polarity="Output" name="b_out" />
        <port polarity="Output" name="c_out" />
        <port polarity="Output" name="e_out" />
        <port polarity="Output" name="f_out" />
        <port polarity="Output" name="g_out" />
        <port polarity="Input" name="A" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="C" />
        <port polarity="Input" name="D" />
        <port polarity="Output" name="d_out" />
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <blockdef name="nand2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="216" y1="-96" y2="-96" x1="256" />
            <circle r="12" cx="204" cy="-96" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
        </blockdef>
        <block symbolname="and2" name="XLXI_25">
            <blockpin signalname="XLXN_9" name="I0" />
            <blockpin signalname="XLXN_8" name="I1" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_26">
            <blockpin signalname="XLXN_11" name="I0" />
            <blockpin signalname="XLXN_10" name="I1" />
            <blockpin signalname="XLXN_7" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_28">
            <blockpin signalname="XLXN_14" name="I0" />
            <blockpin signalname="XLXN_13" name="I1" />
            <blockpin signalname="XLXN_16" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_29">
            <blockpin signalname="B" name="I" />
            <blockpin signalname="XLXN_15" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_30">
            <blockpin signalname="C" name="I" />
            <blockpin signalname="XLXN_13" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_31">
            <blockpin signalname="D" name="I" />
            <blockpin signalname="XLXN_14" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_35">
            <blockpin signalname="D" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_20" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_36">
            <blockpin signalname="D" name="I0" />
            <blockpin signalname="XLXN_25" name="I1" />
            <blockpin signalname="XLXN_23" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_38">
            <blockpin signalname="A" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="XLXN_24" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_39">
            <blockpin signalname="XLXN_24" name="I0" />
            <blockpin signalname="XLXN_23" name="I1" />
            <blockpin signalname="c_out" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_40">
            <blockpin signalname="C" name="I" />
            <blockpin signalname="XLXN_25" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_46">
            <blockpin signalname="XLXN_32" name="I0" />
            <blockpin signalname="XLXN_31" name="I1" />
            <blockpin signalname="XLXN_35" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_47">
            <blockpin signalname="XLXN_34" name="I0" />
            <blockpin signalname="XLXN_35" name="I1" />
            <blockpin signalname="XLXN_36" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_51">
            <blockpin signalname="XLXN_38" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="XLXN_39" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_56">
            <blockpin signalname="XLXN_42" name="I0" />
            <blockpin signalname="XLXN_41" name="I1" />
            <blockpin signalname="XLXN_40" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_57">
            <blockpin signalname="XLXN_45" name="I0" />
            <blockpin signalname="XLXN_44" name="I1" />
            <blockpin signalname="XLXN_47" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_58">
            <blockpin signalname="XLXN_46" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_48" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_59">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_50" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_60">
            <blockpin signalname="XLXN_48" name="I0" />
            <blockpin signalname="XLXN_47" name="I1" />
            <blockpin signalname="XLXN_49" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_61">
            <blockpin signalname="XLXN_50" name="I0" />
            <blockpin signalname="XLXN_49" name="I1" />
            <blockpin signalname="e_out" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_62">
            <blockpin signalname="B" name="I" />
            <blockpin signalname="XLXN_44" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_63">
            <blockpin signalname="D" name="I" />
            <blockpin signalname="XLXN_45" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_64">
            <blockpin signalname="D" name="I" />
            <blockpin signalname="XLXN_46" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_69">
            <blockpin signalname="XLXN_56" name="I0" />
            <blockpin signalname="XLXN_54" name="I1" />
            <blockpin signalname="XLXN_57" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_74">
            <blockpin signalname="XLXN_61" name="I0" />
            <blockpin signalname="XLXN_60" name="I1" />
            <blockpin signalname="XLXN_62" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_78">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_79">
            <blockpin signalname="D" name="I0" />
            <blockpin signalname="D" name="I1" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_80">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="XLXN_12" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_81">
            <blockpin signalname="XLXN_3" name="I0" />
            <blockpin signalname="XLXN_2" name="I1" />
            <blockpin signalname="XLXN_8" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_82">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="XLXN_12" name="I1" />
            <blockpin signalname="XLXN_9" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_83">
            <blockpin signalname="D" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="XLXN_10" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_84">
            <blockpin signalname="A" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_11" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_85">
            <blockpin signalname="XLXN_7" name="I0" />
            <blockpin signalname="XLXN_4" name="I1" />
            <blockpin signalname="a_out" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_86">
            <blockpin signalname="XLXN_16" name="I0" />
            <blockpin signalname="XLXN_15" name="I1" />
            <blockpin signalname="XLXN_18" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_88">
            <blockpin signalname="XLXN_19" name="I0" />
            <blockpin signalname="XLXN_18" name="I1" />
            <blockpin signalname="b_out" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_89">
            <blockpin signalname="A" name="I0" />
            <blockpin signalname="XLXN_20" name="I1" />
            <blockpin signalname="XLXN_19" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_90">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="XLXN_28" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_91">
            <blockpin signalname="D" name="I0" />
            <blockpin signalname="D" name="I1" />
            <blockpin signalname="XLXN_29" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_92">
            <blockpin signalname="XLXN_29" name="I0" />
            <blockpin signalname="XLXN_28" name="I1" />
            <blockpin signalname="XLXN_31" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_93">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="XLXN_30" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_94">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="XLXN_30" name="I1" />
            <blockpin signalname="XLXN_32" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_95">
            <blockpin signalname="XLXN_40" name="I0" />
            <blockpin signalname="XLXN_36" name="I1" />
            <blockpin signalname="d_out" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_96">
            <blockpin signalname="D" name="I0" />
            <blockpin signalname="D" name="I1" />
            <blockpin signalname="XLXN_33" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_97">
            <blockpin signalname="XLXN_33" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_34" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_98">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_38" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_99">
            <blockpin signalname="D" name="I0" />
            <blockpin signalname="XLXN_39" name="I1" />
            <blockpin signalname="XLXN_41" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_100">
            <blockpin signalname="A" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_42" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_101">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="XLXN_61" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_102">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_60" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_103">
            <blockpin signalname="A" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_63" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_104">
            <blockpin signalname="XLXN_63" name="I0" />
            <blockpin signalname="XLXN_62" name="I1" />
            <blockpin signalname="g_out" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_105">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_52" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_106">
            <blockpin signalname="D" name="I0" />
            <blockpin signalname="D" name="I1" />
            <blockpin signalname="XLXN_53" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_107">
            <blockpin signalname="XLXN_53" name="I0" />
            <blockpin signalname="XLXN_52" name="I1" />
            <blockpin signalname="XLXN_54" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_108">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="XLXN_56" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_109">
            <blockpin signalname="A" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_58" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_110">
            <blockpin signalname="XLXN_58" name="I0" />
            <blockpin signalname="XLXN_57" name="I1" />
            <blockpin signalname="f_out" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3801" height="5382">
        <attr value="CM" name="LengthUnitName" />
        <attr value="4" name="GridsPerUnit" />
        <branch name="XLXN_2">
            <wire x2="976" y1="288" y2="288" x1="960" />
            <wire x2="992" y1="288" y2="288" x1="976" />
            <wire x2="992" y1="256" y2="288" x1="992" />
            <wire x2="1024" y1="256" y2="256" x1="992" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="992" y1="416" y2="416" x1="960" />
            <wire x2="992" y1="320" y2="416" x1="992" />
            <wire x2="1024" y1="320" y2="320" x1="992" />
        </branch>
        <instance x="1328" y="480" name="XLXI_25" orien="R0" />
        <instance x="1328" y="832" name="XLXI_26" orien="R0" />
        <branch name="XLXN_4">
            <wire x2="1648" y1="496" y2="496" x1="1536" />
            <wire x2="1536" y1="496" y2="528" x1="1536" />
            <wire x2="1616" y1="528" y2="528" x1="1536" />
            <wire x2="1648" y1="384" y2="384" x1="1584" />
            <wire x2="1648" y1="384" y2="496" x1="1648" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="1536" y1="592" y2="624" x1="1536" />
            <wire x2="1648" y1="624" y2="624" x1="1536" />
            <wire x2="1648" y1="624" y2="736" x1="1648" />
            <wire x2="1616" y1="592" y2="592" x1="1536" />
            <wire x2="1648" y1="736" y2="736" x1="1584" />
        </branch>
        <branch name="XLXN_8">
            <wire x2="1296" y1="288" y2="288" x1="1280" />
            <wire x2="1296" y1="288" y2="352" x1="1296" />
            <wire x2="1328" y1="352" y2="352" x1="1296" />
        </branch>
        <branch name="XLXN_9">
            <wire x2="1296" y1="528" y2="528" x1="1280" />
            <wire x2="1296" y1="416" y2="528" x1="1296" />
            <wire x2="1328" y1="416" y2="416" x1="1296" />
        </branch>
        <branch name="XLXN_10">
            <wire x2="1296" y1="672" y2="672" x1="1280" />
            <wire x2="1296" y1="672" y2="704" x1="1296" />
            <wire x2="1328" y1="704" y2="704" x1="1296" />
        </branch>
        <branch name="XLXN_11">
            <wire x2="1296" y1="816" y2="816" x1="1280" />
            <wire x2="1296" y1="768" y2="816" x1="1296" />
            <wire x2="1328" y1="768" y2="768" x1="1296" />
        </branch>
        <branch name="XLXN_12">
            <wire x2="992" y1="544" y2="544" x1="960" />
            <wire x2="992" y1="496" y2="544" x1="992" />
            <wire x2="1024" y1="496" y2="496" x1="992" />
        </branch>
        <instance x="1024" y="1088" name="XLXI_28" orien="R0" />
        <instance x="864" y="944" name="XLXI_29" orien="R0" />
        <instance x="640" y="992" name="XLXI_30" orien="R0" />
        <instance x="640" y="1072" name="XLXI_31" orien="R0" />
        <branch name="XLXN_13">
            <wire x2="1024" y1="960" y2="960" x1="864" />
        </branch>
        <branch name="XLXN_14">
            <wire x2="944" y1="1040" y2="1040" x1="864" />
            <wire x2="944" y1="1024" y2="1040" x1="944" />
            <wire x2="1024" y1="1024" y2="1024" x1="944" />
        </branch>
        <branch name="XLXN_15">
            <wire x2="1344" y1="912" y2="912" x1="1088" />
        </branch>
        <branch name="XLXN_16">
            <wire x2="1312" y1="992" y2="992" x1="1280" />
            <wire x2="1312" y1="976" y2="992" x1="1312" />
            <wire x2="1344" y1="976" y2="976" x1="1312" />
        </branch>
        <instance x="1024" y="1232" name="XLXI_35" orien="R0" />
        <branch name="XLXN_18">
            <wire x2="1616" y1="944" y2="944" x1="1600" />
            <wire x2="1616" y1="944" y2="992" x1="1616" />
            <wire x2="1632" y1="992" y2="992" x1="1616" />
            <wire x2="1648" y1="992" y2="992" x1="1632" />
        </branch>
        <branch name="XLXN_19">
            <wire x2="1616" y1="1120" y2="1120" x1="1600" />
            <wire x2="1616" y1="1056" y2="1120" x1="1616" />
            <wire x2="1632" y1="1056" y2="1056" x1="1616" />
            <wire x2="1648" y1="1056" y2="1056" x1="1632" />
        </branch>
        <branch name="XLXN_20">
            <wire x2="1312" y1="1136" y2="1136" x1="1280" />
            <wire x2="1312" y1="1088" y2="1136" x1="1312" />
            <wire x2="1344" y1="1088" y2="1088" x1="1312" />
        </branch>
        <branch name="a_out">
            <wire x2="1888" y1="560" y2="560" x1="1872" />
            <wire x2="2176" y1="560" y2="560" x1="1888" />
        </branch>
        <branch name="b_out">
            <wire x2="2192" y1="1024" y2="1024" x1="1904" />
        </branch>
        <instance x="1024" y="1424" name="XLXI_36" orien="R0" />
        <instance x="1024" y="1584" name="XLXI_38" orien="R0" />
        <instance x="1328" y="1504" name="XLXI_39" orien="R0" />
        <branch name="XLXN_23">
            <wire x2="1296" y1="1328" y2="1328" x1="1280" />
            <wire x2="1296" y1="1328" y2="1376" x1="1296" />
            <wire x2="1328" y1="1376" y2="1376" x1="1296" />
        </branch>
        <branch name="XLXN_24">
            <wire x2="1296" y1="1488" y2="1488" x1="1280" />
            <wire x2="1296" y1="1440" y2="1488" x1="1296" />
            <wire x2="1328" y1="1440" y2="1440" x1="1296" />
        </branch>
        <instance x="656" y="1328" name="XLXI_40" orien="R0" />
        <branch name="XLXN_25">
            <wire x2="1024" y1="1296" y2="1296" x1="880" />
        </branch>
        <branch name="c_out">
            <wire x2="2000" y1="1408" y2="1408" x1="1584" />
        </branch>
        <instance x="1312" y="1888" name="XLXI_46" orien="R0" />
        <instance x="1600" y="2064" name="XLXI_47" orien="R0" />
        <branch name="XLXN_28">
            <wire x2="1008" y1="1632" y2="1632" x1="992" />
            <wire x2="1008" y1="1632" y2="1664" x1="1008" />
            <wire x2="1024" y1="1664" y2="1664" x1="1008" />
        </branch>
        <branch name="XLXN_29">
            <wire x2="1008" y1="1760" y2="1760" x1="992" />
            <wire x2="1008" y1="1728" y2="1760" x1="1008" />
            <wire x2="1024" y1="1728" y2="1728" x1="1008" />
        </branch>
        <branch name="XLXN_30">
            <wire x2="1024" y1="1888" y2="1888" x1="992" />
        </branch>
        <branch name="XLXN_31">
            <wire x2="1296" y1="1696" y2="1696" x1="1280" />
            <wire x2="1296" y1="1696" y2="1760" x1="1296" />
            <wire x2="1312" y1="1760" y2="1760" x1="1296" />
        </branch>
        <branch name="XLXN_32">
            <wire x2="1232" y1="1824" y2="1856" x1="1232" />
            <wire x2="1344" y1="1856" y2="1856" x1="1232" />
            <wire x2="1344" y1="1856" y2="1920" x1="1344" />
            <wire x2="1312" y1="1824" y2="1824" x1="1232" />
            <wire x2="1344" y1="1920" y2="1920" x1="1280" />
        </branch>
        <branch name="XLXN_33">
            <wire x2="1312" y1="2208" y2="2208" x1="1296" />
            <wire x2="1312" y1="2128" y2="2208" x1="1312" />
            <wire x2="1328" y1="2128" y2="2128" x1="1312" />
        </branch>
        <branch name="XLXN_34">
            <wire x2="1536" y1="2000" y2="2032" x1="1536" />
            <wire x2="1664" y1="2032" y2="2032" x1="1536" />
            <wire x2="1664" y1="2032" y2="2096" x1="1664" />
            <wire x2="1600" y1="2000" y2="2000" x1="1536" />
            <wire x2="1664" y1="2096" y2="2096" x1="1584" />
        </branch>
        <branch name="XLXN_35">
            <wire x2="1648" y1="1904" y2="1904" x1="1520" />
            <wire x2="1520" y1="1904" y2="1936" x1="1520" />
            <wire x2="1600" y1="1936" y2="1936" x1="1520" />
            <wire x2="1648" y1="1792" y2="1792" x1="1568" />
            <wire x2="1648" y1="1792" y2="1904" x1="1648" />
        </branch>
        <branch name="XLXN_36">
            <wire x2="1872" y1="1968" y2="1968" x1="1856" />
            <wire x2="1872" y1="1968" y2="2064" x1="1872" />
            <wire x2="1904" y1="2064" y2="2064" x1="1872" />
        </branch>
        <instance x="1056" y="2448" name="XLXI_51" orien="R0" />
        <branch name="XLXN_38">
            <wire x2="1040" y1="2464" y2="2464" x1="1024" />
            <wire x2="1040" y1="2384" y2="2464" x1="1040" />
            <wire x2="1056" y1="2384" y2="2384" x1="1040" />
        </branch>
        <branch name="XLXN_39">
            <wire x2="1344" y1="2352" y2="2352" x1="1312" />
        </branch>
        <instance x="1664" y="2560" name="XLXI_56" orien="R0" />
        <branch name="XLXN_40">
            <wire x2="1888" y1="1968" y2="2128" x1="1888" />
            <wire x2="1904" y1="2128" y2="2128" x1="1888" />
            <wire x2="2240" y1="1968" y2="1968" x1="1888" />
            <wire x2="2240" y1="1968" y2="2464" x1="2240" />
            <wire x2="2240" y1="2464" y2="2464" x1="1920" />
        </branch>
        <branch name="XLXN_41">
            <wire x2="1632" y1="2384" y2="2384" x1="1600" />
            <wire x2="1632" y1="2384" y2="2432" x1="1632" />
            <wire x2="1664" y1="2432" y2="2432" x1="1632" />
        </branch>
        <branch name="XLXN_42">
            <wire x2="1632" y1="2528" y2="2528" x1="1600" />
            <wire x2="1632" y1="2496" y2="2528" x1="1632" />
            <wire x2="1664" y1="2496" y2="2496" x1="1632" />
        </branch>
        <instance x="944" y="2784" name="XLXI_57" orien="R0" />
        <instance x="944" y="2928" name="XLXI_58" orien="R0" />
        <instance x="1168" y="3056" name="XLXI_59" orien="R0" />
        <instance x="1280" y="2848" name="XLXI_60" orien="R0" />
        <instance x="1600" y="2960" name="XLXI_61" orien="R0" />
        <instance x="656" y="2688" name="XLXI_62" orien="R0" />
        <instance x="656" y="2752" name="XLXI_63" orien="R0" />
        <instance x="656" y="2896" name="XLXI_64" orien="R0" />
        <branch name="XLXN_44">
            <wire x2="944" y1="2656" y2="2656" x1="880" />
        </branch>
        <branch name="XLXN_45">
            <wire x2="944" y1="2720" y2="2720" x1="880" />
        </branch>
        <branch name="XLXN_46">
            <wire x2="944" y1="2864" y2="2864" x1="880" />
        </branch>
        <branch name="XLXN_47">
            <wire x2="1232" y1="2688" y2="2688" x1="1200" />
            <wire x2="1232" y1="2688" y2="2720" x1="1232" />
            <wire x2="1280" y1="2720" y2="2720" x1="1232" />
        </branch>
        <branch name="XLXN_48">
            <wire x2="1232" y1="2832" y2="2832" x1="1200" />
            <wire x2="1232" y1="2784" y2="2832" x1="1232" />
            <wire x2="1280" y1="2784" y2="2784" x1="1232" />
        </branch>
        <branch name="XLXN_49">
            <wire x2="1568" y1="2752" y2="2752" x1="1536" />
            <wire x2="1568" y1="2752" y2="2832" x1="1568" />
            <wire x2="1600" y1="2832" y2="2832" x1="1568" />
        </branch>
        <branch name="XLXN_50">
            <wire x2="1504" y1="2960" y2="2960" x1="1424" />
            <wire x2="1504" y1="2896" y2="2960" x1="1504" />
            <wire x2="1600" y1="2896" y2="2896" x1="1504" />
        </branch>
        <branch name="e_out">
            <wire x2="2352" y1="2864" y2="2864" x1="1856" />
            <wire x2="2352" y1="2864" y2="2880" x1="2352" />
        </branch>
        <instance x="1392" y="3392" name="XLXI_69" orien="R0" />
        <branch name="XLXN_52">
            <wire x2="1040" y1="3136" y2="3136" x1="992" />
            <wire x2="1040" y1="3136" y2="3168" x1="1040" />
            <wire x2="1088" y1="3168" y2="3168" x1="1040" />
        </branch>
        <branch name="XLXN_53">
            <wire x2="1040" y1="3280" y2="3280" x1="992" />
            <wire x2="1040" y1="3232" y2="3280" x1="1040" />
            <wire x2="1088" y1="3232" y2="3232" x1="1040" />
        </branch>
        <branch name="XLXN_54">
            <wire x2="1360" y1="3200" y2="3200" x1="1344" />
            <wire x2="1360" y1="3200" y2="3264" x1="1360" />
            <wire x2="1392" y1="3264" y2="3264" x1="1360" />
        </branch>
        <branch name="XLXN_56">
            <wire x2="1360" y1="3424" y2="3424" x1="1344" />
            <wire x2="1392" y1="3328" y2="3328" x1="1360" />
            <wire x2="1360" y1="3328" y2="3424" x1="1360" />
        </branch>
        <branch name="XLXN_57">
            <wire x2="1680" y1="3296" y2="3296" x1="1648" />
            <wire x2="1680" y1="3296" y2="3392" x1="1680" />
            <wire x2="1712" y1="3392" y2="3392" x1="1680" />
        </branch>
        <branch name="XLXN_58">
            <wire x2="1680" y1="3584" y2="3584" x1="1664" />
            <wire x2="1680" y1="3456" y2="3584" x1="1680" />
            <wire x2="1712" y1="3456" y2="3456" x1="1680" />
        </branch>
        <branch name="f_out">
            <wire x2="2400" y1="3424" y2="3424" x1="1968" />
            <wire x2="2416" y1="3424" y2="3424" x1="2400" />
        </branch>
        <instance x="1136" y="3968" name="XLXI_74" orien="R0" />
        <branch name="XLXN_60">
            <wire x2="1088" y1="3744" y2="3744" x1="1040" />
            <wire x2="1088" y1="3744" y2="3840" x1="1088" />
            <wire x2="1136" y1="3840" y2="3840" x1="1088" />
        </branch>
        <branch name="XLXN_61">
            <wire x2="1088" y1="3952" y2="3952" x1="1040" />
            <wire x2="1088" y1="3904" y2="3952" x1="1088" />
            <wire x2="1136" y1="3904" y2="3904" x1="1088" />
        </branch>
        <branch name="XLXN_62">
            <wire x2="1424" y1="3872" y2="3872" x1="1392" />
            <wire x2="1424" y1="3872" y2="4000" x1="1424" />
            <wire x2="1456" y1="4000" y2="4000" x1="1424" />
        </branch>
        <branch name="XLXN_63">
            <wire x2="1424" y1="4192" y2="4192" x1="1408" />
            <wire x2="1424" y1="4064" y2="4192" x1="1424" />
            <wire x2="1456" y1="4064" y2="4064" x1="1424" />
        </branch>
        <branch name="g_out">
            <wire x2="2368" y1="4032" y2="4032" x1="1712" />
        </branch>
        <iomarker fontsize="28" x="2176" y="560" name="a_out" orien="R0" />
        <iomarker fontsize="28" x="2192" y="1024" name="b_out" orien="R0" />
        <iomarker fontsize="28" x="2000" y="1408" name="c_out" orien="R0" />
        <branch name="A">
            <wire x2="352" y1="288" y2="288" x1="304" />
            <wire x2="368" y1="288" y2="288" x1="352" />
            <wire x2="368" y1="288" y2="784" x1="368" />
            <wire x2="1024" y1="784" y2="784" x1="368" />
            <wire x2="368" y1="784" y2="848" x1="368" />
            <wire x2="368" y1="848" y2="864" x1="368" />
            <wire x2="368" y1="864" y2="1216" x1="368" />
            <wire x2="368" y1="1216" y2="1232" x1="368" />
            <wire x2="368" y1="1232" y2="1520" x1="368" />
            <wire x2="368" y1="1520" y2="1536" x1="368" />
            <wire x2="368" y1="1536" y2="2544" x1="368" />
            <wire x2="368" y1="2544" y2="2624" x1="368" />
            <wire x2="368" y1="2624" y2="2960" x1="368" />
            <wire x2="768" y1="2960" y2="2960" x1="368" />
            <wire x2="368" y1="2960" y2="3552" x1="368" />
            <wire x2="368" y1="3552" y2="3568" x1="368" />
            <wire x2="368" y1="3568" y2="3648" x1="368" />
            <wire x2="880" y1="3648" y2="3648" x1="368" />
            <wire x2="368" y1="3648" y2="4160" x1="368" />
            <wire x2="368" y1="4160" y2="4224" x1="368" />
            <wire x2="1152" y1="4224" y2="4224" x1="368" />
            <wire x2="1152" y1="4160" y2="4160" x1="368" />
            <wire x2="1408" y1="3552" y2="3552" x1="368" />
            <wire x2="1216" y1="2544" y2="2544" x1="368" />
            <wire x2="1024" y1="1520" y2="1520" x1="368" />
            <wire x2="1360" y1="1216" y2="1216" x1="368" />
            <wire x2="1360" y1="1216" y2="1232" x1="1360" />
            <wire x2="1024" y1="848" y2="848" x1="368" />
            <wire x2="352" y1="2592" y2="2624" x1="352" />
            <wire x2="368" y1="2624" y2="2624" x1="352" />
            <wire x2="1344" y1="2592" y2="2592" x1="352" />
            <wire x2="1344" y1="2592" y2="2608" x1="1344" />
            <wire x2="768" y1="2928" y2="2960" x1="768" />
            <wire x2="1168" y1="2928" y2="2928" x1="768" />
            <wire x2="880" y1="3616" y2="3648" x1="880" />
            <wire x2="1408" y1="3616" y2="3616" x1="880" />
            <wire x2="1344" y1="2496" y2="2496" x1="1216" />
            <wire x2="1216" y1="2496" y2="2544" x1="1216" />
            <wire x2="1344" y1="1152" y2="1152" x1="1296" />
            <wire x2="1296" y1="1152" y2="1232" x1="1296" />
            <wire x2="1360" y1="1232" y2="1232" x1="1296" />
            <wire x2="1344" y1="2560" y2="2560" x1="1328" />
            <wire x2="1328" y1="2560" y2="2608" x1="1328" />
            <wire x2="1344" y1="2608" y2="2608" x1="1328" />
        </branch>
        <branch name="B">
            <wire x2="448" y1="384" y2="384" x1="304" />
            <wire x2="448" y1="384" y2="512" x1="448" />
            <wire x2="704" y1="512" y2="512" x1="448" />
            <wire x2="448" y1="512" y2="576" x1="448" />
            <wire x2="704" y1="576" y2="576" x1="448" />
            <wire x2="448" y1="576" y2="672" x1="448" />
            <wire x2="448" y1="672" y2="912" x1="448" />
            <wire x2="448" y1="912" y2="928" x1="448" />
            <wire x2="448" y1="928" y2="1456" x1="448" />
            <wire x2="448" y1="1456" y2="1600" x1="448" />
            <wire x2="736" y1="1600" y2="1600" x1="448" />
            <wire x2="448" y1="1600" y2="1664" x1="448" />
            <wire x2="736" y1="1664" y2="1664" x1="448" />
            <wire x2="448" y1="1664" y2="1856" x1="448" />
            <wire x2="736" y1="1856" y2="1856" x1="448" />
            <wire x2="448" y1="1856" y2="1920" x1="448" />
            <wire x2="448" y1="1920" y2="1936" x1="448" />
            <wire x2="448" y1="1936" y2="2320" x1="448" />
            <wire x2="448" y1="2320" y2="2656" x1="448" />
            <wire x2="448" y1="2656" y2="2992" x1="448" />
            <wire x2="448" y1="2992" y2="3392" x1="448" />
            <wire x2="448" y1="3392" y2="3456" x1="448" />
            <wire x2="448" y1="3456" y2="3472" x1="448" />
            <wire x2="448" y1="3472" y2="3920" x1="448" />
            <wire x2="448" y1="3920" y2="4000" x1="448" />
            <wire x2="784" y1="3920" y2="3920" x1="448" />
            <wire x2="1088" y1="3456" y2="3456" x1="448" />
            <wire x2="1088" y1="3392" y2="3392" x1="448" />
            <wire x2="1168" y1="2992" y2="2992" x1="448" />
            <wire x2="656" y1="2656" y2="2656" x1="448" />
            <wire x2="1040" y1="2320" y2="2320" x1="448" />
            <wire x2="1056" y1="2320" y2="2320" x1="1040" />
            <wire x2="736" y1="1920" y2="1920" x1="448" />
            <wire x2="1024" y1="1456" y2="1456" x1="448" />
            <wire x2="864" y1="912" y2="912" x1="448" />
            <wire x2="960" y1="672" y2="672" x1="448" />
            <wire x2="992" y1="672" y2="672" x1="960" />
            <wire x2="784" y1="3984" y2="3984" x1="432" />
            <wire x2="432" y1="3984" y2="4000" x1="432" />
            <wire x2="448" y1="4000" y2="4000" x1="432" />
            <wire x2="448" y1="240" y2="256" x1="448" />
            <wire x2="704" y1="256" y2="256" x1="448" />
            <wire x2="448" y1="256" y2="320" x1="448" />
            <wire x2="448" y1="320" y2="336" x1="448" />
            <wire x2="448" y1="336" y2="384" x1="448" />
            <wire x2="704" y1="320" y2="320" x1="448" />
            <wire x2="992" y1="640" y2="672" x1="992" />
            <wire x2="1024" y1="640" y2="640" x1="992" />
        </branch>
        <iomarker fontsize="28" x="304" y="288" name="A" orien="R180" />
        <iomarker fontsize="28" x="304" y="384" name="B" orien="R180" />
        <branch name="C">
            <wire x2="496" y1="480" y2="480" x1="320" />
            <wire x2="496" y1="480" y2="656" x1="496" />
            <wire x2="816" y1="656" y2="656" x1="496" />
            <wire x2="496" y1="656" y2="960" x1="496" />
            <wire x2="640" y1="960" y2="960" x1="496" />
            <wire x2="496" y1="960" y2="1104" x1="496" />
            <wire x2="1024" y1="1104" y2="1104" x1="496" />
            <wire x2="496" y1="1104" y2="1296" x1="496" />
            <wire x2="496" y1="1296" y2="2016" x1="496" />
            <wire x2="496" y1="2016" y2="2080" x1="496" />
            <wire x2="496" y1="2080" y2="2432" x1="496" />
            <wire x2="768" y1="2432" y2="2432" x1="496" />
            <wire x2="496" y1="2432" y2="2496" x1="496" />
            <wire x2="496" y1="2496" y2="2800" x1="496" />
            <wire x2="496" y1="2800" y2="3104" x1="496" />
            <wire x2="736" y1="3104" y2="3104" x1="496" />
            <wire x2="496" y1="3104" y2="3168" x1="496" />
            <wire x2="496" y1="3168" y2="3712" x1="496" />
            <wire x2="496" y1="3712" y2="3776" x1="496" />
            <wire x2="784" y1="3776" y2="3776" x1="496" />
            <wire x2="784" y1="3712" y2="3712" x1="496" />
            <wire x2="736" y1="3168" y2="3168" x1="496" />
            <wire x2="944" y1="2800" y2="2800" x1="496" />
            <wire x2="768" y1="2496" y2="2496" x1="496" />
            <wire x2="512" y1="2080" y2="2080" x1="496" />
            <wire x2="752" y1="2016" y2="2016" x1="496" />
            <wire x2="656" y1="1296" y2="1296" x1="496" />
            <wire x2="1328" y1="2064" y2="2064" x1="512" />
            <wire x2="512" y1="2064" y2="2080" x1="512" />
            <wire x2="752" y1="1952" y2="2016" x1="752" />
            <wire x2="1024" y1="1952" y2="1952" x1="752" />
            <wire x2="976" y1="640" y2="640" x1="816" />
            <wire x2="816" y1="640" y2="656" x1="816" />
            <wire x2="976" y1="560" y2="640" x1="976" />
            <wire x2="1024" y1="560" y2="560" x1="976" />
        </branch>
        <branch name="D">
            <wire x2="560" y1="608" y2="608" x1="336" />
            <wire x2="560" y1="608" y2="704" x1="560" />
            <wire x2="1024" y1="704" y2="704" x1="560" />
            <wire x2="560" y1="704" y2="1040" x1="560" />
            <wire x2="640" y1="1040" y2="1040" x1="560" />
            <wire x2="560" y1="1040" y2="1168" x1="560" />
            <wire x2="1024" y1="1168" y2="1168" x1="560" />
            <wire x2="560" y1="1168" y2="1360" x1="560" />
            <wire x2="560" y1="1360" y2="1376" x1="560" />
            <wire x2="560" y1="1376" y2="1744" x1="560" />
            <wire x2="560" y1="1744" y2="1792" x1="560" />
            <wire x2="560" y1="1792" y2="2176" x1="560" />
            <wire x2="560" y1="2176" y2="2192" x1="560" />
            <wire x2="560" y1="2192" y2="2240" x1="560" />
            <wire x2="560" y1="2240" y2="2528" x1="560" />
            <wire x2="560" y1="2528" y2="2720" x1="560" />
            <wire x2="560" y1="2720" y2="2864" x1="560" />
            <wire x2="560" y1="2864" y2="3248" x1="560" />
            <wire x2="560" y1="3248" y2="3312" x1="560" />
            <wire x2="720" y1="3312" y2="3312" x1="560" />
            <wire x2="736" y1="3312" y2="3312" x1="720" />
            <wire x2="736" y1="3248" y2="3248" x1="560" />
            <wire x2="656" y1="2864" y2="2864" x1="560" />
            <wire x2="656" y1="2720" y2="2720" x1="560" />
            <wire x2="1056" y1="2528" y2="2528" x1="560" />
            <wire x2="1040" y1="2240" y2="2240" x1="560" />
            <wire x2="1040" y1="2176" y2="2176" x1="560" />
            <wire x2="736" y1="1792" y2="1792" x1="560" />
            <wire x2="1024" y1="1360" y2="1360" x1="560" />
            <wire x2="736" y1="1728" y2="1728" x1="544" />
            <wire x2="544" y1="1728" y2="1744" x1="544" />
            <wire x2="560" y1="1744" y2="1744" x1="544" />
            <wire x2="704" y1="384" y2="384" x1="560" />
            <wire x2="560" y1="384" y2="448" x1="560" />
            <wire x2="560" y1="448" y2="608" x1="560" />
            <wire x2="704" y1="448" y2="448" x1="560" />
            <wire x2="1344" y1="2416" y2="2416" x1="1056" />
            <wire x2="1056" y1="2416" y2="2528" x1="1056" />
        </branch>
        <iomarker fontsize="28" x="2352" y="2880" name="e_out" orien="R90" />
        <iomarker fontsize="28" x="2416" y="3424" name="f_out" orien="R0" />
        <iomarker fontsize="28" x="2368" y="4032" name="g_out" orien="R0" />
        <iomarker fontsize="28" x="320" y="480" name="C" orien="R180" />
        <iomarker fontsize="28" x="336" y="608" name="D" orien="R180" />
        <branch name="d_out">
            <wire x2="2192" y1="2096" y2="2096" x1="2160" />
        </branch>
        <iomarker fontsize="28" x="2192" y="2096" name="d_out" orien="R0" />
        <instance x="704" y="384" name="XLXI_78" orien="R0" />
        <instance x="704" y="512" name="XLXI_79" orien="R0" />
        <instance x="704" y="640" name="XLXI_80" orien="R0" />
        <instance x="1024" y="384" name="XLXI_81" orien="R0" />
        <instance x="1024" y="624" name="XLXI_82" orien="R0" />
        <instance x="1024" y="768" name="XLXI_83" orien="R0" />
        <instance x="1024" y="912" name="XLXI_84" orien="R0" />
        <instance x="1616" y="656" name="XLXI_85" orien="R0" />
        <instance x="1344" y="1040" name="XLXI_86" orien="R0" />
        <instance x="1648" y="1120" name="XLXI_88" orien="R0" />
        <instance x="1344" y="1216" name="XLXI_89" orien="R0" />
        <instance x="736" y="1728" name="XLXI_90" orien="R0" />
        <instance x="736" y="1856" name="XLXI_91" orien="R0" />
        <instance x="1024" y="1792" name="XLXI_92" orien="R0" />
        <instance x="736" y="1984" name="XLXI_93" orien="R0" />
        <instance x="1024" y="2016" name="XLXI_94" orien="R0" />
        <instance x="1904" y="2192" name="XLXI_95" orien="R0" />
        <instance x="1040" y="2304" name="XLXI_96" orien="R0" />
        <instance x="1328" y="2192" name="XLXI_97" orien="R0" />
        <instance x="768" y="2560" name="XLXI_98" orien="R0" />
        <instance x="1344" y="2480" name="XLXI_99" orien="R0" />
        <instance x="1344" y="2624" name="XLXI_100" orien="R0" />
        <instance x="784" y="4048" name="XLXI_101" orien="R0" />
        <instance x="784" y="3840" name="XLXI_102" orien="R0" />
        <instance x="1152" y="4288" name="XLXI_103" orien="R0" />
        <instance x="1456" y="4128" name="XLXI_104" orien="R0" />
        <instance x="736" y="3232" name="XLXI_105" orien="R0" />
        <instance x="736" y="3376" name="XLXI_106" orien="R0" />
        <instance x="1088" y="3296" name="XLXI_107" orien="R0" />
        <instance x="1088" y="3520" name="XLXI_108" orien="R0" />
        <instance x="1408" y="3680" name="XLXI_109" orien="R0" />
        <instance x="1712" y="3520" name="XLXI_110" orien="R0" />
    </sheet>
</drawing>