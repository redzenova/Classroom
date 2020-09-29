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
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="H_P55" />
        <signal name="S_P56" />
        <signal name="B_P57" />
        <signal name="D_P58" />
        <signal name="XLXN_41" />
        <signal name="XLXN_44" />
        <signal name="E_P59" />
        <signal name="XLXN_47" />
        <signal name="Buzzer_P83" />
        <port polarity="Input" name="H_P55" />
        <port polarity="Input" name="S_P56" />
        <port polarity="Input" name="B_P57" />
        <port polarity="Input" name="D_P58" />
        <port polarity="Input" name="E_P59" />
        <port polarity="Output" name="Buzzer_P83" />
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
        <blockdef name="or4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="48" y1="-256" y2="-256" x1="0" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <arc ex="112" ey="-208" sx="192" sy="-160" r="88" cx="116" cy="-120" />
            <line x2="48" y1="-208" y2="-208" x1="112" />
            <line x2="48" y1="-112" y2="-112" x1="112" />
            <line x2="48" y1="-256" y2="-208" x1="48" />
            <line x2="48" y1="-64" y2="-112" x1="48" />
            <arc ex="48" ey="-208" sx="48" sy="-112" r="56" cx="16" cy="-160" />
            <arc ex="192" ey="-160" sx="112" sy="-112" r="88" cx="116" cy="-200" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="XLXN_1" name="I0" />
            <blockpin signalname="H_P55" name="I1" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="E_P59" name="I0" />
            <blockpin signalname="XLXN_2" name="I1" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="D_P58" name="I0" />
            <blockpin signalname="XLXN_8" name="I1" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="E_P59" name="I0" />
            <blockpin signalname="XLXN_7" name="I1" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_5">
            <blockpin signalname="XLXN_9" name="I0" />
            <blockpin signalname="S_P56" name="I1" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_6">
            <blockpin signalname="XLXN_10" name="I0" />
            <blockpin signalname="B_P57" name="I1" />
            <blockpin signalname="XLXN_8" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_7">
            <blockpin signalname="XLXN_6" name="I0" />
            <blockpin signalname="XLXN_5" name="I1" />
            <blockpin signalname="XLXN_4" name="I2" />
            <blockpin signalname="XLXN_3" name="I3" />
            <blockpin signalname="Buzzer_P83" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_8">
            <blockpin signalname="E_P59" name="I" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_9">
            <blockpin signalname="B_P57" name="I" />
            <blockpin signalname="XLXN_9" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_10">
            <blockpin signalname="S_P56" name="I" />
            <blockpin signalname="XLXN_10" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_11">
            <blockpin signalname="D_P58" name="I" />
            <blockpin signalname="XLXN_7" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1088" y="400" name="XLXI_1" orien="R0" />
        <instance x="1088" y="656" name="XLXI_2" orien="R0" />
        <instance x="1088" y="912" name="XLXI_3" orien="R0" />
        <instance x="1088" y="1216" name="XLXI_4" orien="R0" />
        <instance x="720" y="624" name="XLXI_5" orien="R0" />
        <instance x="720" y="880" name="XLXI_6" orien="R0" />
        <instance x="1520" y="816" name="XLXI_7" orien="R0" />
        <instance x="720" y="368" name="XLXI_8" orien="R0" />
        <instance x="416" y="592" name="XLXI_9" orien="R0" />
        <instance x="432" y="848" name="XLXI_10" orien="R0" />
        <instance x="752" y="1120" name="XLXI_11" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1088" y1="336" y2="336" x1="944" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="1088" y1="528" y2="528" x1="976" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="1520" y1="304" y2="304" x1="1344" />
            <wire x2="1520" y1="304" y2="560" x1="1520" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="1424" y1="560" y2="560" x1="1344" />
            <wire x2="1424" y1="560" y2="624" x1="1424" />
            <wire x2="1520" y1="624" y2="624" x1="1424" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="1424" y1="816" y2="816" x1="1344" />
            <wire x2="1424" y1="688" y2="816" x1="1424" />
            <wire x2="1520" y1="688" y2="688" x1="1424" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="1520" y1="1120" y2="1120" x1="1344" />
            <wire x2="1520" y1="752" y2="1120" x1="1520" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="1088" y1="1088" y2="1088" x1="976" />
        </branch>
        <branch name="XLXN_8">
            <wire x2="1088" y1="784" y2="784" x1="976" />
        </branch>
        <branch name="XLXN_9">
            <wire x2="720" y1="560" y2="560" x1="640" />
        </branch>
        <branch name="XLXN_10">
            <wire x2="720" y1="816" y2="816" x1="656" />
        </branch>
        <branch name="H_P55">
            <wire x2="1088" y1="272" y2="272" x1="192" />
        </branch>
        <branch name="S_P56">
            <wire x2="240" y1="352" y2="352" x1="192" />
            <wire x2="240" y1="352" y2="496" x1="240" />
            <wire x2="720" y1="496" y2="496" x1="240" />
            <wire x2="240" y1="496" y2="816" x1="240" />
            <wire x2="432" y1="816" y2="816" x1="240" />
        </branch>
        <iomarker fontsize="28" x="192" y="272" name="H_P55" orien="R180" />
        <iomarker fontsize="28" x="192" y="352" name="S_P56" orien="R180" />
        <iomarker fontsize="28" x="176" y="752" name="B_P57" orien="R180" />
        <branch name="B_P57">
            <wire x2="416" y1="752" y2="752" x1="176" />
            <wire x2="720" y1="752" y2="752" x1="416" />
            <wire x2="416" y1="560" y2="752" x1="416" />
        </branch>
        <branch name="D_P58">
            <wire x2="752" y1="928" y2="928" x1="176" />
            <wire x2="976" y1="928" y2="928" x1="752" />
            <wire x2="752" y1="928" y2="1088" x1="752" />
            <wire x2="1088" y1="848" y2="848" x1="976" />
            <wire x2="976" y1="848" y2="928" x1="976" />
        </branch>
        <iomarker fontsize="28" x="176" y="928" name="D_P58" orien="R180" />
        <branch name="E_P59">
            <wire x2="352" y1="1152" y2="1152" x1="176" />
            <wire x2="656" y1="1152" y2="1152" x1="352" />
            <wire x2="1088" y1="1152" y2="1152" x1="656" />
            <wire x2="352" y1="336" y2="672" x1="352" />
            <wire x2="656" y1="672" y2="672" x1="352" />
            <wire x2="672" y1="672" y2="672" x1="656" />
            <wire x2="976" y1="672" y2="672" x1="672" />
            <wire x2="352" y1="672" y2="1152" x1="352" />
            <wire x2="720" y1="336" y2="336" x1="352" />
            <wire x2="1088" y1="592" y2="592" x1="976" />
            <wire x2="976" y1="592" y2="672" x1="976" />
        </branch>
        <iomarker fontsize="28" x="176" y="1152" name="E_P59" orien="R180" />
        <branch name="Buzzer_P83">
            <wire x2="1808" y1="656" y2="656" x1="1776" />
        </branch>
        <iomarker fontsize="28" x="1808" y="656" name="Buzzer_P83" orien="R0" />
    </sheet>
</drawing>