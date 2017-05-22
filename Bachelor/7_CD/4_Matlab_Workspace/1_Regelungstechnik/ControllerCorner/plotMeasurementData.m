function [t, phi2, phi3, uk1, uk2, uk3, ur1, ur2, ur3, tm1, tm2, tm3] = plotMeasurementData(phiFile, ukFile, urFile, tmFile, plotFlag)
    if nargin < 5
        plotFlag = true;
    end

    [tphi, phi2, phi3]   = importPhi(phiFile);
    [tuk, uk1, uk2, uk3] = importUK(ukFile);
    [tur, ur1, ur2, ur3] = importUR(urFile);
    [ttm, tm1, tm2, tm3] = importTM(tmFile);
    t = tphi;

    if(plotFlag == true)
        h_phi = emlFigure();
        p_phi = plot(tphi, [phi2, phi3]); grid;
        emlXLabel('Time in seconds');
        emlYLabel('$\varphi_i$ in radians');
        emlTitle('$\varphi_i$ over Time');
        emlLegend({'$\varphi_2$', '$\varphi_3$'});

        emlFigure();
        plot(tuk, [uk1, uk2, uk3]); grid;
        emlXLabel('Time in seconds');
        emlYLabel('$u_{Ki}$ in radians per second');
        emlTitle('$u_{Ki}$ over Time');
        emlLegend({'$u_{K1}$', '$u_{K2}$', '$u_{K3}$'});

        emlFigure();
        plot(tur, [ur1, ur2, ur3]); grid;
        emlXLabel('Time in seconds');
        emlYLabel('$u_{Ri}$ in radians per second');
        emlTitle('$u_{Ri}$ over Time');
        emlLegend({'$u_{R1}$', '$u_{R2}$', '$u_{R3}$'});

        emlFigure();
        plot(ttm, [tm1, tm2, tm3]); grid;
        emlXLabel('Time in seconds');
        emlYLabel('$T_{Mi}$ in Nm');
        emlTitle('$T_{Mi}$ over Time');
        emlLegend({'$T_{M1}$', '$T_{M2}$', '$T_{M3}$'});
    end
end