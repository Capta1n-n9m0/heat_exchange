P = 101325

R = 8.3144598
Md = 0.0289652
Mv = 0.01801528

def density(T, P_air, P_vap):
    return (P_air*Md + P_vap*Mv)/(R*T)
