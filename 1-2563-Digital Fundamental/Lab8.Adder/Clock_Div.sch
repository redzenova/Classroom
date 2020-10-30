<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_52" />
        <signal name="XLXN_56" />
        <signal name="Clock_IN" />
        <signal name="Q(15:0)" />
        <signal name="Q(15)" />
        <signal name="CLKTo7Seg" />
        <port polarity="Input" name="Clock_IN" />
        <port polarity="Output" name="CLKTo7Seg" />
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
        </blockdef>
        <blockdef name="cb16ce">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="320" y1="-192" y2="-192" x1="384" />
            <rect width="64" x="320" y="-268" height="24" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-32" y2="-32" x1="192" />
            <line x2="192" y1="-64" y2="-32" x1="192" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="320" y1="-128" y2="-128" x1="384" />
            <rect width="256" x="64" y="-320" height="256" />
        </blockdef>
        <blockdef name="gnd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-96" x1="64" />
            <line x2="52" y1="-48" y2="-48" x1="76" />
            <line x2="60" y1="-32" y2="-32" x1="68" />
            <line x2="40" y1="-64" y2="-64" x1="88" />
            <line x2="64" y1="-64" y2="-80" x1="64" />
            <line x2="64" y1="-128" y2="-96" x1="64" />
        </blockdef>
        <blockdef name="buf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="0" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-64" x1="128" />
            <line x2="64" y1="-64" y2="0" x1="64" />
        </blockdef>
        <block symbolname="vcc" name="XLXI_37">
            <blockpin signalname="XLXN_52" name="P" />
        </block>
        <block symbolname="cb16ce" name="XLXI_40">
            <blockpin signalname="Clock_IN" name="C" />
            <blockpin signalname="XLXN_52" name="CE" />
            <blockpin signalname="XLXN_56" name="CLR" />
            <blockpin name="CEO" />
            <blockpin signalname="Q(15:0)" name="Q(15:0)" />
            <blockpin name="TC" />
        </block>
        <block symbolname="gnd" name="XLXI_38">
            <blockpin signalname="XLXN_56" name="G" />
        </block>
        <block symbolname="buf" name="XLXI_41">
            <blockpin signalname="Q(15)" name="I" />
            <blockpin signalname="CLKTo7Seg" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="XLXN_52">
            <wire x2="1072" y1="992" y2="1072" x1="1072" />
            <wire x2="1264" y1="1072" y2="1072" x1="1072" />
        </branch>
        <instance x="1264" y="1264" name="XLXI_40" orien="R0" />
        <branch name="Clock_IN">
            <wire x2="1264" y1="1136" y2="1136" x1="1088" />
        </branch>
        <bustap x2="1920" y1="1072" y2="1072" x1="1824" />
        <branch name="Q(15:0)">
            <wire x2="1824" y1="1008" y2="1008" x1="1648" />
            <wire x2="1824" y1="1008" y2="1072" x1="1824" />
        </branch>
        <branch name="Q(15)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1936" y="1072" type="branch" />
            <wire x2="1936" y1="1072" y2="1072" x1="1920" />
            <wire x2="1984" y1="1072" y2="1072" x1="1936" />
        </branch>
        <branch name="CLKTo7Seg">
            <wire x2="2288" y1="1072" y2="1072" x1="2208" />
        </branch>
        <instance x="1984" y="1104" name="XLXI_41" orien="R0" />
        <iomarker fontsize="28" x="1088" y="1136" name="Clock_IN" orien="R180" />
        <iomarker fontsize="28" x="2288" y="1072" name="CLKTo7Seg" orien="R0" />
        <instance x="1024" y="1376" name="XLXI_38" orien="R0" />
        <branch name="XLXN_56">
            <wire x2="1088" y1="1232" y2="1248" x1="1088" />
            <wire x2="1264" y1="1232" y2="1232" x1="1088" />
        </branch>
        <instance x="1008" y="992" name="XLXI_37" orien="R0" />
    </sheet>
</drawing>