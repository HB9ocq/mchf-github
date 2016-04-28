/*  -*-  mode: c; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4; coding: utf-8  -*-  */
/************************************************************************************
**                                                                                 **
**                               mcHF QRP Transceiver                              **
**                             K Atanassov - M0NKA 2014                            **
**                                                                                 **
**---------------------------------------------------------------------------------**
**                                                                                 **
**  File name:                                                                     **
**  Description:                                                                   **
**  Last Modified:                                                                 **
**  Licence:		CC BY-NC-SA 3.0                                                **
************************************************************************************/

#include "filters.h"
/*
 	 * Hilbert 0 Degree, "Phase-added" bandpass filter
     * Kaiser Window FIR Filter, Beta = 5.00, Raised Cosine = 0.90
     * Fc = 1.97 kHz
     * BW = 3.74 kHz
     * 89 Taps
     *
     * 20141203 by KA7OEI using Iowa Hills Hilbert Filter Designer
     *
     * This filter used in the "3.6 kHz" and narrower RX filter position of the mcHF
*/

const float i_rx_3k6_coeffs[I_NUM_TAPS] =
{
    -0.000181752008817777,
    -0.00019812444299558,
    -0.000173915580313638,
    -0.000106975730010085,
    -0.0000174463735378,
    0.000049667546759971,
    0.000032561004630231,
    -0.000127681493947272,
    -0.000459708207577463,
    -0.000935771201527816,
    -0.00145865712043841,
    -0.00187227346724911,
    -0.00200036401889901,
    -0.00170780689629204,
    -0.000967958368014592,
    0.000088289293095689,
    0.001166623215145986,
    0.001862531622450524,
    0.001771946721352388,
    0.000635741675713185,
    -0.00152451719575799,
    -0.00433057882661493,
    -0.00707443210838268,
    -0.00886614749018614,
    -0.00888315684570901,
    -0.00666207782636225,
    -0.0023460199801576,
    0.003204723474564544,
    0.008506335530971061,
    0.011765956147501436,
    0.011367103182967093,
    0.006413424630698947,
    -0.00282047953175066,
    -0.0146812039524101,
    -0.0262751422843746,
    -0.0339730971952901,
    -0.0341994964523126,
    -0.0243347165617545,
    -0.00350726050818481,
    0.026942155121425213,
    0.063476622132557281,
    0.100898465799951861,
    0.133312097666693830,
    0.155307720769003010,
    0.163093615613067344,
    0.155307720769004343,
    0.133312097666696161,
    0.100898465799954873,
    0.063476622132560459,
    0.026942155121428071,
    -0.00350726050818265,
    -0.0243347165617533,
    -0.0341994964523123,
    -0.0339730971952905,
    -0.0262751422843754,
    -0.0146812039524111,
    -0.00282047953175152,
    0.006413424630698421,
    0.011367103182966964,
    0.011765956147501661,
    0.008506335530971517,
    0.003204723474565072,
    -0.00234601998015715,
    -0.00666207782636198,
    -0.00888315684570896,
    -0.00886614749018627,
    -0.00707443210838294,
    -0.00433057882661522,
    -0.00152451719575822,
    0.000635741675713052,
    0.001771946721352369,
    0.001862531622450603,
    0.001166623215146122,
    0.000088289293095838,
    -0.00096795836801447,
    -0.00170780689629197,
    -0.002000364018899,
    -0.00187227346724914,
    -0.00145865712043846,
    -0.000935771201527874,
    -0.000459708207577509,
    -0.000127681493947298,
    0.000032561004630225,
    0.000049667546759980,
    -0.000017446373537785,
    -0.00010697573001007,
    -0.000173915580313629,
    -0.000198124442995578,
    -0.000181752
};

/*
 	 * Hilbert -90 Degree, "Phase-added" bandpass filter
 	 * Kaiser Window FIR Filter, Beta = 5.00, Raised Cosine = 0.90
     * Fc = 1.97 kHz
     * BW = 3.74 kHz
     * 89 Taps
     *
     * 20141203 by KA7OEI using Iowa Hills Hilbert Filter Designer
     *
     * This filter used in the "3.6 kHz" and narrower RX filter positions of the mcHF
*/

const float q_rx_3k6_coeffs[Q_NUM_TAPS] =
{
    -0.000294806871446761,
    -0.000430038513938049,
    -0.00057577635651954,
    -0.000701452460068679,
    -0.000773483568490036,
    -0.000770724776536896,
    -0.000701666832263429,
    -0.000616113554803381,
    -0.000603644067469941,
    -0.00077404001429163,
    -0.00122090559459946,
    -0.00197736129120186,
    -0.00297920572331694,
    -0.00405321865749724,
    -0.00494407320037525,
    -0.00538239440020133,
    -0.00518124403535075,
    -0.00433349474961163,
    -0.00307403519977391,
    -0.00187345276484406,
    -0.00134566807456456,
    -0.00207838789258401,
    -0.00442514292801338,
    -0.00832115293523963,
    -0.0131925136715957,
    -0.0180131059057811,
    -0.0215266256625295,
    -0.0226003081681251,
    -0.0206265730133377,
    -0.0158556828219807,
    -0.00954049290906044,
    -0.00380949445236171,
    -0.00125158785236759,
    -0.00427935828129978,
    -0.0144137579244869,
    -0.0316779221618311,
    -0.0542839354303643,
    -0.0787391229290012,
    -0.100398818306822,
    -0.114375118099481,
    -0.116607805332378,
    -0.104844680649768,
    -0.0792835060106304,
    -0.0426990455969243,
    -1.802423033856850E-15,
    0.042699045596920997,
    0.079283506010627697,
    0.104844680649766375,
    0.116607805332377912,
    0.114375118099481379,
    0.100398818306823789,
    0.078739122929003105,
    0.054283935430366234,
    0.031677922161832718,
    0.014413757924488018,
    0.004279358281300266,
    0.001251587852367549,
    0.003809494452361318,
    0.009540492909059896,
    0.015855682821980240,
    0.020626573013337410,
    0.022600308168125034,
    0.021526625662529674,
    0.018013105905781469,
    0.013192513671596058,
    0.008321152935239943,
    0.004425142928013570,
    0.002078387892584060,
    0.001345668074564481,
    0.001873452764843904,
    0.003074035199773733,
    0.004333494749611476,
    0.005181244035350659,
    0.005382394400201308,
    0.004944073200375284,
    0.004053218657497318,
    0.002979205723317022,
    0.001977361291201922,
    0.001220905594599500,
    0.000774040014291644,
    0.000603644067469934,
    0.000616113554803364,
    0.000701666832263413,
    0.000770724776536887,
    0.000773483568490036,
    0.000701452460068687,
    0.000575776356519553,
    0.000430038513938061,
    0.000294806871446770
};
#if 0
//
// Same as above, but set to -89.50 degrees
//
const float q_rx_3k6_coeffs_minus[Q_NUM_TAPS] =
{
    -0.000296380721462183,
    -0.000431750013359223,
    -0.000577271201466755,
    -0.000702358759671733,
    -0.000773606358243193,
    -0.000770262377749341,
    -0.000701356238932302,
    -0.000617203666244525,
    -0.000607630221322245,
    -0.000782171394601014,
    -0.00123358004541336,
    -0.00199361413363922,
    -0.00299653760381988,
    -0.00406795841390126,
    -0.00495232700454705,
    -0.00538142014572859,
    -0.00517087338199056,
    -0.0043170873311676,
    -0.00305846556626572,
    -0.00186783742193235,
    -0.00135891214852496,
    -0.00211607551610032,
    -0.00448667032679334,
    -0.00839815781424639,
    -0.0132694819909666,
    -0.0180705214653967,
    -0.0215462679892084,
    -0.0225715023079523,
    -0.0205516072815124,
    -0.0157524713736376,
    -0.00944099951243712,
    -0.00375341907618676,
    -0.00127613744482971,
    -0.00440722904942769,
    -0.0146423535178151,
    -0.0319729955136686,
    -0.0545801251563832,
    -0.0789483547584795,
    -0.100425594029681,
    -0.114135817274525,
    -0.11604980662169,
    -0.103960776559558,
    -0.0781178963313035,
    -0.0413430030557385,
    0.001422321813111582,
    0.044051846785323458,
    0.080443097152319953,
    0.105720625812728841,
    0.117156952158226857,
    0.114605736526452867,
    0.100364421149232066,
    0.078523913886879862,
    0.053983624924064215,
    0.031380444088303247,
    0.014184068159762866,
    0.004151162660246889,
    0.001226943249871537,
    0.003865280643724892,
    0.009639262071620981,
    0.015957690640103335,
    0.020699972949044482,
    0.022627398402789923,
    0.021505349215297679,
    0.017954322942512063,
    0.013114543887430948,
    0.008243516384216850,
    0.004363279609562653,
    0.002040542495321605,
    0.001332321848790194,
    0.001878925890962495,
    0.003089371478357671,
    0.004349573205544231,
    0.005191221372196609,
    0.005382960068514172,
    0.004935444083706319,
    0.004038171214788057,
    0.002961647686546919,
    0.001960958344109158,
    0.001208138462890931,
    0.000765849875367875,
    0.000599612090031858,
    0.000614976673197738,
    0.000701924160944054,
    0.000771128668375053,
    0.000773302062363184,
    0.000700492912088482,
    0.000574237803469036,
    0.000428294369606101,
    0.000293210642170642
};
//
//
// Same as above, but set to -90.50 degrees
//
const float q_rx_3k6_coeffs_plus[Q_NUM_TAPS] =
{
    -0.000293210642170637,
    -0.000428294369606096,
    -0.000574237803469034,
    -0.000700492912088486,
    -0.000773302062363194,
    -0.00077112866837507,
    -0.000701924160944074,
    -0.000614976673197755,
    -0.000599612090031863,
    -0.000765849875367862,
    -0.00120813846289089,
    -0.0019609583441091,
    -0.00296164768654685,
    -0.004038171214788,
    -0.00493544408370629,
    -0.00538296006851418,
    -0.00519122137219667,
    -0.00434957320554433,
    -0.00308937147835778,
    -0.00187892589096257,
    -0.00133232184879019,
    -0.00204054249532148,
    -0.0043632796095624,
    -0.00824351638421651,
    -0.0131145438874306,
    -0.0179543229425118,
    -0.0215053492152976,
    -0.02262739840279,
    -0.0206999729490448,
    -0.0159576906401039,
    -0.00963926207162155,
    -0.00386528064372531,
    -0.00122694324987159,
    -0.00415116266024643,
    -0.0141840681597618,
    -0.0313804440883017,
    -0.0539836249240624,
    -0.0785239138868781,
    -0.100364421149231,
    -0.114605736526452,
    -0.117156952158227,
    -0.10572062581273,
    -0.0804430971523225,
    -0.0440518467853267,
    -0.00142232181311506,
    0.041343003055735225,
    0.078117896331300937,
    0.103960776559556239,
    0.116049806621689372,
    0.114135817274525875,
    0.100425594029682583,
    0.078948354758481304,
    0.054580125156385072,
    0.031972995513670166,
    0.014642353517816205,
    0.004407229049428166,
    0.001276137444829668,
    0.003753419076186360,
    0.009440999512436554,
    0.015752471373637049,
    0.020551607281512018,
    0.022571502307952233,
    0.021546267989208483,
    0.018070521465396977,
    0.013269481990966999,
    0.008398157814246731,
    0.004486670326793598,
    0.002116075516100453,
    0.001358912148524973,
    0.001867837421932283,
    0.003058465566265609,
    0.004317087331167497,
    0.005170873381990497,
    0.005381420145728581,
    0.004952327004547082,
    0.004067958413901318,
    0.002996537603819948,
    0.001993614133639282,
    0.001233580045413398,
    0.000782171394601029,
    0.000607630221322240,
    0.000617203666244509,
    0.000701356238932283,
    0.000770262377749325,
    0.000773606358243183,
    0.000702358759671730,
    0.000577271201466757,
    0.000431750013359228,
    0.000296380721462188
};
#endif
