<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="Cin" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="B" />
        <signal name="A" />
        <signal name="SUM" />
        <signal name="Cout" />
        <port polarity="Input" name="Cin" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="A" />
        <port polarity="Output" name="SUM" />
        <port polarity="Output" name="Cout" />
        <blockdef name="xor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <line x2="208" y1="-96" y2="-96" x1="256" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
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
        <block symbolname="xor2" name="XLXI_1">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_2">
            <blockpin signalname="Cin" name="I0" />
            <blockpin signalname="XLXN_3" name="I1" />
            <blockpin signalname="SUM" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="XLXN_3" name="I0" />
            <blockpin signalname="Cin" name="I1" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_5">
            <blockpin signalname="XLXN_2" name="I0" />
            <blockpin signalname="XLXN_1" name="I1" />
            <blockpin signalname="Cout" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="640" y="960" name="XLXI_1" orien="R0" />
        <instance x="1136" y="992" name="XLXI_2" orien="R0" />
        <instance x="944" y="1200" name="XLXI_3" orien="R0" />
        <instance x="944" y="1392" name="XLXI_4" orien="R0" />
        <instance x="1312" y="1280" name="XLXI_5" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1248" y1="1104" y2="1104" x1="1200" />
            <wire x2="1248" y1="1104" y2="1152" x1="1248" />
            <wire x2="1312" y1="1152" y2="1152" x1="1248" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="1248" y1="1296" y2="1296" x1="1200" />
            <wire x2="1248" y1="1216" y2="1296" x1="1248" />
            <wire x2="1312" y1="1216" y2="1216" x1="1248" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="912" y1="864" y2="864" x1="896" />
            <wire x2="912" y1="864" y2="1136" x1="912" />
            <wire x2="944" y1="1136" y2="1136" x1="912" />
            <wire x2="1136" y1="864" y2="864" x1="912" />
        </branch>
        <branch name="Cin">
            <wire x2="896" y1="992" y2="992" x1="368" />
            <wire x2="896" y1="992" y2="1000" x1="896" />
            <wire x2="896" y1="1000" y2="1072" x1="896" />
            <wire x2="944" y1="1072" y2="1072" x1="896" />
            <wire x2="1136" y1="928" y2="928" x1="896" />
            <wire x2="896" y1="928" y2="992" x1="896" />
        </branch>
        <branch name="B">
            <wire x2="480" y1="896" y2="896" x1="368" />
            <wire x2="640" y1="896" y2="896" x1="480" />
            <wire x2="480" y1="896" y2="1328" x1="480" />
            <wire x2="944" y1="1328" y2="1328" x1="480" />
        </branch>
        <branch name="A">
            <wire x2="544" y1="832" y2="832" x1="368" />
            <wire x2="640" y1="832" y2="832" x1="544" />
            <wire x2="544" y1="832" y2="1264" x1="544" />
            <wire x2="944" y1="1264" y2="1264" x1="544" />
        </branch>
        <branch name="SUM">
            <wire x2="1600" y1="896" y2="896" x1="1392" />
        </branch>
        <branch name="Cout">
            <wire x2="1632" y1="1184" y2="1184" x1="1568" />
        </branch>
        <iomarker fontsize="28" x="368" y="832" name="A" orien="R180" />
        <iomarker fontsize="28" x="368" y="896" name="B" orien="R180" />
        <iomarker fontsize="28" x="368" y="992" name="Cin" orien="R180" />
        <iomarker fontsize="28" x="1600" y="896" name="SUM" orien="R0" />
        <iomarker fontsize="28" x="1632" y="1184" name="Cout" orien="R0" />
    </sheet>
</drawing>