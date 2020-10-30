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
        <signal name="A(0:7)" />
        <signal name="A(0)" />
        <signal name="A(1)" />
        <signal name="A(2)" />
        <signal name="A(3)" />
        <signal name="A(4)" />
        <signal name="A(5)" />
        <signal name="A(6)" />
        <signal name="A(7)" />
        <signal name="B(0:7)" />
        <signal name="B(0)" />
        <signal name="B(2)" />
        <signal name="B(3)" />
        <signal name="B(4)" />
        <signal name="B(5)" />
        <signal name="B(6)" />
        <signal name="B(7)" />
        <signal name="B(1)" />
        <signal name="Cin" />
        <signal name="SUM(0:7)" />
        <signal name="SUM(0)" />
        <signal name="SUM(1)" />
        <signal name="SUM(2)" />
        <signal name="SUM(3)" />
        <signal name="SUM(4)" />
        <signal name="SUM(5)" />
        <signal name="SUM(6)" />
        <signal name="SUM(7)" />
        <signal name="Cout" />
        <port polarity="Input" name="A(0:7)" />
        <port polarity="Input" name="B(0:7)" />
        <port polarity="Input" name="Cin" />
        <port polarity="Output" name="SUM(0:7)" />
        <port polarity="Output" name="Cout" />
        <blockdef name="FullAdder">
            <timestamp>2020-10-29T3:3:14</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="FullAdder" name="XLXI_1">
            <blockpin signalname="Cin" name="Cin" />
            <blockpin signalname="B(0)" name="B" />
            <blockpin signalname="A(0)" name="A" />
            <blockpin signalname="SUM(0)" name="SUM" />
            <blockpin signalname="XLXN_1" name="Cout" />
        </block>
        <block symbolname="FullAdder" name="XLXI_2">
            <blockpin signalname="XLXN_1" name="Cin" />
            <blockpin signalname="B(1)" name="B" />
            <blockpin signalname="A(1)" name="A" />
            <blockpin signalname="SUM(1)" name="SUM" />
            <blockpin signalname="XLXN_2" name="Cout" />
        </block>
        <block symbolname="FullAdder" name="XLXI_3">
            <blockpin signalname="XLXN_2" name="Cin" />
            <blockpin signalname="B(2)" name="B" />
            <blockpin signalname="A(2)" name="A" />
            <blockpin signalname="SUM(2)" name="SUM" />
            <blockpin signalname="XLXN_3" name="Cout" />
        </block>
        <block symbolname="FullAdder" name="XLXI_4">
            <blockpin signalname="XLXN_3" name="Cin" />
            <blockpin signalname="B(3)" name="B" />
            <blockpin signalname="A(3)" name="A" />
            <blockpin signalname="SUM(3)" name="SUM" />
            <blockpin signalname="XLXN_4" name="Cout" />
        </block>
        <block symbolname="FullAdder" name="XLXI_5">
            <blockpin signalname="XLXN_5" name="Cin" />
            <blockpin signalname="B(5)" name="B" />
            <blockpin signalname="A(5)" name="A" />
            <blockpin signalname="SUM(5)" name="SUM" />
            <blockpin signalname="XLXN_6" name="Cout" />
        </block>
        <block symbolname="FullAdder" name="XLXI_6">
            <blockpin signalname="XLXN_6" name="Cin" />
            <blockpin signalname="B(6)" name="B" />
            <blockpin signalname="A(6)" name="A" />
            <blockpin signalname="SUM(6)" name="SUM" />
            <blockpin signalname="XLXN_7" name="Cout" />
        </block>
        <block symbolname="FullAdder" name="XLXI_7">
            <blockpin signalname="XLXN_7" name="Cin" />
            <blockpin signalname="B(7)" name="B" />
            <blockpin signalname="A(7)" name="A" />
            <blockpin signalname="SUM(7)" name="SUM" />
            <blockpin signalname="Cout" name="Cout" />
        </block>
        <block symbolname="FullAdder" name="XLXI_8">
            <blockpin signalname="XLXN_4" name="Cin" />
            <blockpin signalname="B(4)" name="B" />
            <blockpin signalname="A(4)" name="A" />
            <blockpin signalname="SUM(4)" name="SUM" />
            <blockpin signalname="XLXN_5" name="Cout" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="800" y="320" name="XLXI_1" orien="R0">
        </instance>
        <instance x="800" y="640" name="XLXI_2" orien="R0">
        </instance>
        <instance x="800" y="960" name="XLXI_3" orien="R0">
        </instance>
        <instance x="800" y="1264" name="XLXI_4" orien="R0">
        </instance>
        <instance x="800" y="1968" name="XLXI_5" orien="R0">
        </instance>
        <instance x="800" y="2288" name="XLXI_6" orien="R0">
        </instance>
        <instance x="800" y="1648" name="XLXI_8" orien="R0">
        </instance>
        <branch name="XLXN_1">
            <wire x2="736" y1="384" y2="480" x1="736" />
            <wire x2="800" y1="480" y2="480" x1="736" />
            <wire x2="1264" y1="384" y2="384" x1="736" />
            <wire x2="1264" y1="288" y2="288" x1="1184" />
            <wire x2="1264" y1="288" y2="384" x1="1264" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="1264" y1="688" y2="688" x1="736" />
            <wire x2="736" y1="688" y2="800" x1="736" />
            <wire x2="800" y1="800" y2="800" x1="736" />
            <wire x2="1264" y1="608" y2="608" x1="1184" />
            <wire x2="1264" y1="608" y2="688" x1="1264" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="736" y1="1008" y2="1104" x1="736" />
            <wire x2="800" y1="1104" y2="1104" x1="736" />
            <wire x2="1264" y1="1008" y2="1008" x1="736" />
            <wire x2="1264" y1="928" y2="928" x1="1184" />
            <wire x2="1264" y1="928" y2="1008" x1="1264" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="1264" y1="1360" y2="1360" x1="720" />
            <wire x2="720" y1="1360" y2="1488" x1="720" />
            <wire x2="800" y1="1488" y2="1488" x1="720" />
            <wire x2="1264" y1="1232" y2="1232" x1="1184" />
            <wire x2="1264" y1="1232" y2="1360" x1="1264" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="736" y1="1696" y2="1808" x1="736" />
            <wire x2="800" y1="1808" y2="1808" x1="736" />
            <wire x2="1264" y1="1696" y2="1696" x1="736" />
            <wire x2="1264" y1="1616" y2="1616" x1="1184" />
            <wire x2="1264" y1="1616" y2="1696" x1="1264" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="736" y1="2032" y2="2128" x1="736" />
            <wire x2="800" y1="2128" y2="2128" x1="736" />
            <wire x2="1264" y1="2032" y2="2032" x1="736" />
            <wire x2="1264" y1="1936" y2="1936" x1="1184" />
            <wire x2="1264" y1="1936" y2="2032" x1="1264" />
        </branch>
        <instance x="800" y="2624" name="XLXI_7" orien="R0">
        </instance>
        <branch name="XLXN_7">
            <wire x2="720" y1="2352" y2="2464" x1="720" />
            <wire x2="800" y1="2464" y2="2464" x1="720" />
            <wire x2="1200" y1="2352" y2="2352" x1="720" />
            <wire x2="1200" y1="2256" y2="2256" x1="1184" />
            <wire x2="1200" y1="2256" y2="2352" x1="1200" />
        </branch>
        <branch name="A(0:7)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="336" y="400" type="branch" />
            <wire x2="336" y1="160" y2="272" x1="336" />
            <wire x2="336" y1="272" y2="288" x1="336" />
            <wire x2="336" y1="288" y2="384" x1="336" />
            <wire x2="336" y1="384" y2="400" x1="336" />
            <wire x2="336" y1="400" y2="464" x1="336" />
            <wire x2="336" y1="464" y2="496" x1="336" />
            <wire x2="336" y1="496" y2="608" x1="336" />
            <wire x2="336" y1="608" y2="928" x1="336" />
            <wire x2="336" y1="928" y2="1232" x1="336" />
            <wire x2="336" y1="1232" y2="1616" x1="336" />
            <wire x2="336" y1="1616" y2="1936" x1="336" />
            <wire x2="336" y1="1936" y2="2256" x1="336" />
            <wire x2="336" y1="2256" y2="2592" x1="336" />
            <wire x2="336" y1="2592" y2="2608" x1="336" />
        </branch>
        <bustap x2="432" y1="288" y2="288" x1="336" />
        <branch name="A(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="448" y="288" type="branch" />
            <wire x2="448" y1="288" y2="288" x1="432" />
            <wire x2="800" y1="288" y2="288" x1="448" />
        </branch>
        <bustap x2="432" y1="608" y2="608" x1="336" />
        <branch name="A(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="480" y="608" type="branch" />
            <wire x2="480" y1="608" y2="608" x1="432" />
            <wire x2="800" y1="608" y2="608" x1="480" />
        </branch>
        <bustap x2="432" y1="928" y2="928" x1="336" />
        <branch name="A(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="480" y="928" type="branch" />
            <wire x2="480" y1="928" y2="928" x1="432" />
            <wire x2="800" y1="928" y2="928" x1="480" />
        </branch>
        <bustap x2="432" y1="1232" y2="1232" x1="336" />
        <branch name="A(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="480" y="1232" type="branch" />
            <wire x2="480" y1="1232" y2="1232" x1="432" />
            <wire x2="800" y1="1232" y2="1232" x1="480" />
        </branch>
        <bustap x2="432" y1="1616" y2="1616" x1="336" />
        <branch name="A(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="464" y="1616" type="branch" />
            <wire x2="464" y1="1616" y2="1616" x1="432" />
            <wire x2="800" y1="1616" y2="1616" x1="464" />
        </branch>
        <bustap x2="432" y1="1936" y2="1936" x1="336" />
        <branch name="A(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="464" y="1936" type="branch" />
            <wire x2="464" y1="1936" y2="1936" x1="432" />
            <wire x2="800" y1="1936" y2="1936" x1="464" />
        </branch>
        <bustap x2="432" y1="2256" y2="2256" x1="336" />
        <branch name="A(6)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="464" y="2256" type="branch" />
            <wire x2="464" y1="2256" y2="2256" x1="432" />
            <wire x2="800" y1="2256" y2="2256" x1="464" />
        </branch>
        <bustap x2="432" y1="2592" y2="2592" x1="336" />
        <branch name="A(7)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="464" y="2592" type="branch" />
            <wire x2="464" y1="2592" y2="2592" x1="432" />
            <wire x2="800" y1="2592" y2="2592" x1="464" />
        </branch>
        <branch name="B(0:7)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="560" y="400" type="branch" />
            <wire x2="560" y1="160" y2="224" x1="560" />
            <wire x2="560" y1="224" y2="400" x1="560" />
            <wire x2="560" y1="400" y2="544" x1="560" />
            <wire x2="560" y1="544" y2="864" x1="560" />
            <wire x2="560" y1="864" y2="1168" x1="560" />
            <wire x2="560" y1="1168" y2="1552" x1="560" />
            <wire x2="560" y1="1552" y2="1872" x1="560" />
            <wire x2="560" y1="1872" y2="2192" x1="560" />
            <wire x2="560" y1="2192" y2="2528" x1="560" />
        </branch>
        <iomarker fontsize="28" x="560" y="160" name="B(0:7)" orien="R270" />
        <iomarker fontsize="28" x="336" y="160" name="A(0:7)" orien="R270" />
        <bustap x2="656" y1="224" y2="224" x1="560" />
        <branch name="B(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="688" y="224" type="branch" />
            <wire x2="688" y1="224" y2="224" x1="656" />
            <wire x2="800" y1="224" y2="224" x1="688" />
        </branch>
        <bustap x2="656" y1="544" y2="544" x1="560" />
        <branch name="B(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="672" y="544" type="branch" />
            <wire x2="672" y1="544" y2="544" x1="656" />
            <wire x2="800" y1="544" y2="544" x1="672" />
        </branch>
        <bustap x2="656" y1="864" y2="864" x1="560" />
        <branch name="B(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="672" y="864" type="branch" />
            <wire x2="672" y1="864" y2="864" x1="656" />
            <wire x2="800" y1="864" y2="864" x1="672" />
        </branch>
        <bustap x2="656" y1="1168" y2="1168" x1="560" />
        <branch name="B(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="672" y="1168" type="branch" />
            <wire x2="672" y1="1168" y2="1168" x1="656" />
            <wire x2="800" y1="1168" y2="1168" x1="672" />
        </branch>
        <bustap x2="656" y1="1552" y2="1552" x1="560" />
        <branch name="B(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="672" y="1552" type="branch" />
            <wire x2="672" y1="1552" y2="1552" x1="656" />
            <wire x2="800" y1="1552" y2="1552" x1="672" />
        </branch>
        <bustap x2="656" y1="1872" y2="1872" x1="560" />
        <branch name="B(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="672" y="1872" type="branch" />
            <wire x2="672" y1="1872" y2="1872" x1="656" />
            <wire x2="800" y1="1872" y2="1872" x1="672" />
        </branch>
        <bustap x2="656" y1="2192" y2="2192" x1="560" />
        <branch name="B(6)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="672" y="2192" type="branch" />
            <wire x2="672" y1="2192" y2="2192" x1="656" />
            <wire x2="800" y1="2192" y2="2192" x1="672" />
        </branch>
        <bustap x2="656" y1="2528" y2="2528" x1="560" />
        <branch name="B(7)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="672" y="2528" type="branch" />
            <wire x2="672" y1="2528" y2="2528" x1="656" />
            <wire x2="800" y1="2528" y2="2528" x1="672" />
        </branch>
        <branch name="Cin">
            <wire x2="784" y1="112" y2="112" x1="752" />
            <wire x2="784" y1="112" y2="160" x1="784" />
            <wire x2="800" y1="160" y2="160" x1="784" />
        </branch>
        <iomarker fontsize="28" x="752" y="112" name="Cin" orien="R180" />
        <branch name="SUM(0:7)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1424" y="224" type="branch" />
            <wire x2="1424" y1="160" y2="224" x1="1424" />
            <wire x2="1424" y1="224" y2="480" x1="1424" />
            <wire x2="1424" y1="480" y2="800" x1="1424" />
            <wire x2="1424" y1="800" y2="1104" x1="1424" />
            <wire x2="1424" y1="1104" y2="1488" x1="1424" />
            <wire x2="1424" y1="1488" y2="1808" x1="1424" />
            <wire x2="1424" y1="1808" y2="2128" x1="1424" />
            <wire x2="1424" y1="2128" y2="2464" x1="1424" />
            <wire x2="1424" y1="2464" y2="2528" x1="1424" />
        </branch>
        <bustap x2="1328" y1="160" y2="160" x1="1424" />
        <branch name="SUM(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1296" y="160" type="branch" />
            <wire x2="1296" y1="160" y2="160" x1="1184" />
            <wire x2="1328" y1="160" y2="160" x1="1296" />
        </branch>
        <bustap x2="1328" y1="480" y2="480" x1="1424" />
        <branch name="SUM(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1248" y="480" type="branch" />
            <wire x2="1248" y1="480" y2="480" x1="1184" />
            <wire x2="1328" y1="480" y2="480" x1="1248" />
        </branch>
        <bustap x2="1328" y1="800" y2="800" x1="1424" />
        <branch name="SUM(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="800" type="branch" />
            <wire x2="1232" y1="800" y2="800" x1="1184" />
            <wire x2="1328" y1="800" y2="800" x1="1232" />
        </branch>
        <bustap x2="1328" y1="1104" y2="1104" x1="1424" />
        <branch name="SUM(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1104" type="branch" />
            <wire x2="1232" y1="1104" y2="1104" x1="1184" />
            <wire x2="1328" y1="1104" y2="1104" x1="1232" />
        </branch>
        <bustap x2="1328" y1="1488" y2="1488" x1="1424" />
        <branch name="SUM(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1216" y="1488" type="branch" />
            <wire x2="1216" y1="1488" y2="1488" x1="1184" />
            <wire x2="1328" y1="1488" y2="1488" x1="1216" />
        </branch>
        <bustap x2="1328" y1="1808" y2="1808" x1="1424" />
        <branch name="SUM(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1216" y="1808" type="branch" />
            <wire x2="1216" y1="1808" y2="1808" x1="1184" />
            <wire x2="1328" y1="1808" y2="1808" x1="1216" />
        </branch>
        <bustap x2="1328" y1="2128" y2="2128" x1="1424" />
        <branch name="SUM(6)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1200" y="2128" type="branch" />
            <wire x2="1200" y1="2128" y2="2128" x1="1184" />
            <wire x2="1328" y1="2128" y2="2128" x1="1200" />
        </branch>
        <bustap x2="1328" y1="2464" y2="2464" x1="1424" />
        <branch name="SUM(7)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1216" y="2464" type="branch" />
            <wire x2="1216" y1="2464" y2="2464" x1="1184" />
            <wire x2="1328" y1="2464" y2="2464" x1="1216" />
        </branch>
        <iomarker fontsize="28" x="1424" y="2528" name="SUM(0:7)" orien="R90" />
        <branch name="Cout">
            <wire x2="1216" y1="2592" y2="2592" x1="1184" />
        </branch>
        <iomarker fontsize="28" x="1216" y="2592" name="Cout" orien="R0" />
    </sheet>
</drawing>