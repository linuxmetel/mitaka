/**************************************************************************************************

Copyright (c) 2007   Tsunehiko Kato  and  4D2U Project, National Astronomical Observatory of Japan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

以下に定める条件に従い、本ソフトウェアおよび関連文書のファイル（以下「ソフトウェア」）の複製を取得す
るすべての人に対し、ソフトウェアを無制限に扱うことを無償で許可します。これには、ソフトウェアの複製を
使用、複写、変更、結合、掲載、頒布、サブライセンス、および/または販売する権利、およびソフトウェアを
提供する相手に同じことを許可する権利も無制限に含まれます。

上記の著作権表示および本許諾表示を、ソフトウェアのすべての複製または重要な部分に記載するものとしま
す。

ソフトウェアは「現状のまま」で、明示であるか暗黙であるかを問わず、何らの保証もなく提供されます。ここ
でいう保証とは、商品性、特定の目的への適合性、および権利非侵害についての保証も含みますが、それに限定
されるものではありません。 作者または著作権者は、契約行為、不法行為、またはそれ以外であろうと、ソフ
トウェアに起因または関連し、あるいはソフトウェアの使用またはその他の扱いによって生じる一切の請求、損
害、その他の義務について何らの責任も負わないものとします。
***************************************************************************************************/
#include  "mtk_lunar_pos.h"
#include  "../common/astro/astrometry.h"

// 「天体の位置計算」長沢江著（地人書館）より


const double lmd_c[][3] = {
	6.2887,		338.915,	4771.9886,
	1.2740,		107.248,	-4133.3536,
	0.6583,		51.668,		8905.3422,
	0.2136,		317.831,	9543.9773,
	0.1856,		176.531,	359.9905,
	
	0.1143,		292.463,	9664.0404,
	0.0588,		86.16,		638.635,
	0.0572,		103.78,		-3773.363,
	0.0533,		30.58,		13677.331,
	0.0459,		124.86,		-8545.352,
	
	0.0410,		342.38,		4411.998,
	0.0348,		25.83,		4452.671,
	0.0305,		155.45,		5131.979,
	0.0153,		240.79,		758.698,
	0.0125,		271.38,		14436.029,
	
	0.0110,		226.45,		-4892.052,
	0.0107,		55.58,		-13038.696,
	0.0100,		296.75,		14315.966,
	0.0085,		34.5,		-8266.71,
	0.0079,		290.7,		-4493.34,

	0.0068,		228.2,		9265.33,
	0.0052,		133.1,		319.32,
	0.0050,		202.4,		4812.66,
	0.0048,		68.6,		-19.34,
	0.0040,		34.1,		13317.34,

	0.0040,		9.5,		18449.32,
	0.0040,		93.8,		-1.33,
	0.0039,		103.3,		17810.68,
	0.0037,		65.1,		5410.62,
	0.0027,		321.3,		9183.99,

	0.0026,		174.8,		-13797.39,
	0.0024,		82.7,		998.63,
	0.0024,		4.7,		9224.66,
	0.0022,		121.4,		-8185.36,
	0.0021,		134.4,		9903.97,

	0.0021,		173.1,		719.98,
	0.0021,		100.3,		-3413.37,
	0.0020,		248.6,		-19.34,
	0.0018,		98.1,		4013.29,
	0.0016,		344.1,		18569.38,

	0.0012,		52.1,		-12678.71,
	0.0011,		250.3,		19208.02,
	0.0009,		81.0,		-8586.0,
	0.0008,		207.0,		14037.3,
	0.0008,		31.0,		-7906.7,

	0.0007,		346.0,		4052.0,
	0.0007,		294.0,		-4853.3,
	0.0007,		90.0,		278.6,
	0.0006,		237.0,		1118.7,
	0.0005,		82.0,		22582.7,

	0.0005,		276.0,		19088.0,
	0.0005,		73.0,		-17450.7,
	0.0005,		112.0,		5091.3,
	0.0004,		116.0,		-398.7,
	0.0004,		25.0,		-120.1,

	0.0004,		181.0,		9584.7,
	0.0004,		18.0,		720.0,
	0.0003,		60.0,		-3814.0,
	0.0003,		13.0,		-3494.7,
	0.0003,		13.0,		18089.3,

	0.0003,		152.0,		5492.0,
	0.0003,		317.0,		-40.7,
	0.0003,		348.0,		23221.3
};

const double A_c[][3] = {
	0.0040,		93.8,		-1.33,
	0.0020,		248.6,		-19.34,
	0.0006,		66.0,		0.2,
	0.0006,		249.0,		-19.3
};

const double beta_c[][3] = {
	5.1282,		236.231,	4832.0202,
	0.2806,		215.147,	9604.0088,
	0.2777,		77.316,		60.0316,
	0.1732,		4.563,		-4073.3220,
	0.0554,		308.98,		8965.374,

	0.0463,		343.48,		698.667,
	0.0326,		287.90,		13737.362,
	0.0172,		194.06,		14375.997,
	0.0093,		25.6,		-8845.31,
	0.0088,		98.4,		-4711.96,

	0.0082,		1.1,		-3713.33,
	0.0043,		322.4,		5470.66,
	0.0042,		266.8,		18509.35,
	0.0034,		188.0,		-4433.31,
	0.0025,		312.5,		8605.38,

	0.0022,		291.4,		13377.37,
	0.0021,		340.0,		1058.66,
	0.0019,		218.6,		9244.02,
	0.0018,		291.8,		-8206.68,
	0.0018,		52.8,		5192.01,

	0.0017,		168.7,		14496.06,
	0.0016,		73.8,		420.02,
	0.0015,		262.1,		9284.69,
	0.0015,		31.7,		9964.00,
	0.0014,		260.8,		-299.96,

	0.0013,		239.7,		4472.03,
	0.0013,		30.4,		379.35,
	0.0012,		304.9,		4812.68,
	0.0012,		12.4,		-4851.36,
	0.0011,		173.0,		19147.99,

	0.0010,		312.9,		-12978.66,
	0.0008,		1.0,		17870.7,
	0.0008,		190.0,		9724.1,
	0.0007,		22.0,		13098.7,
	0.0006,		117.0,		5590.7,

	0.0006,		47.0,		-13617.3,
	0.0005,		22.0,		-8485.3,
	0.0005,		150.0,		4193.4,
	0.0004,		119.0,		-9483.9,
	0.0004,		246.0,		23281.3,

	0.0004,		301.0,		10242.6,
	0.0004,		126.0,		9325.4,
	0.0004,		104.0,		14097.4,
	0.0003,		340.0,		22642.7,
	0.0003,		270.0,		18149.4,

	0.0003,		358.0,		-3353.3,
	0.0003,		148.0,		19268.0
};

const double B_c[][3] = {
	0.0267,		68.64,		-19.341,
	0.0043,		342.0,		-19.36,
	0.0040,		93.8,		-1.33,
	0.0020,		248.6,		-19.34,
	0.0005,		358.0,		-19.4
};

const double sinpi_c[][3] = {
	0.0518,		338.92,		4771.989,
	0.0095,		287.2,		-4133.35,
	0.0078,		51.7,		8905.34,
	0.0028,		317.8,		9543.98,
	0.0009,		31.0,		13677.3,

	0.0005,		305.0,		-8545.4,
	0.0004,		284.0,		-3773.4,
	0.0003,		342.0,		4412.0
};

vector3d
calc_lunar_pos(const double& t)
{
	const double pi = 3.14159265358979;
	const double d2r = pi / 180.0;

	//----------
	//  calc T
	//----------
	double dt, T;
	dt = (t - (2442413 - 0.5)) / 365.25;
	T = dt + (0.0317*dt + 1.43) * 1e-6;

	//----------------
	//  calc A and B
	//----------------
	double A, B;
	A = 0.0;
	for (int i=0; i<4; i++) {
		A += A_c[i][0] * sin( d2r * (A_c[i][1] + A_c[i][2] * T) );
	}
	B = 0.0;
	for (int i=0; i<5; i++) {
		B += B_c[i][0] * sin( d2r * (B_c[i][1] + B_c[i][2] * T) );
	}

	//------------------------------
	//  calc lmd, beta and sin(pi)
	//------------------------------
	double lmd, beta, sinpi;
	
	lmd  = 124.8754 + 4812.67881 * T;
	lmd += lmd_c[0][0] * sin( d2r * (lmd_c[0][1] + lmd_c[0][2] * T + A) );
	for (int i=1; i<63; i++) {
		lmd += lmd_c[i][0] * sin( d2r * (lmd_c[i][1] + lmd_c[i][2] * T) );
	}

	beta = beta_c[0][0] * sin( d2r * (beta_c[0][1] + beta_c[0][2] * T + B) );
	for (int i=1; i<47; i++) {
		beta += beta_c[i][0] * sin( d2r * (beta_c[i][1] + beta_c[i][2] * T) );
	}

	sinpi = 0.9507;
	for (int i=0; i<8; i++) {
		sinpi += sinpi_c[i][0] * cos( d2r * (sinpi_c[i][1] + sinpi_c[i][2] * T) );
	}

	//---------------------------
	//  rectangular coordinates
	//---------------------------
	double dist, cosb;
	lmd   *= d2r;
	beta  *= d2r;
	sinpi *= d2r;

	dist = 6378.140 / sinpi;
	cosb = cos(beta);
	vector3d  r_ec = dist * vector3d(cosb*cos(lmd), cosb*sin(lmd), sin(beta));

	//-----------------------------------
	// 瞬時の黄道座標から J2000 の黄道座標へ
	//-----------------------------------
	const double eps0 = 84381.406;
	double zeta_A, z_A, theta_A, eps_A;
	double t1, t2, t3, t4, t5;

	t1 = (t - 2451545.0) / 36525.0;
	t2 = t1 * t1;
	t3 = t2 * t1;
	t4 = t3 * t1;
	t5 = t4 * t1;

	zeta_A  =  2.650545 + 2306.083227 * t1 + 0.2988499 * t2 + 0.01801828 * t3 - 0.000005971 * t4 - 0.0000003173 * t5;
	z_A     = -2.650545 + 2306.077181 * t1 + 1.0927348 * t2 + 0.01826837 * t3 - 0.000028596 * t4 - 0.0000002904 * t5;
	theta_A =             2004.191903 * t1 - 0.4294934 * t2 - 0.04182264 * t3 - 0.000007089 * t4 - 0.0000001274 * t5;
	eps_A   = eps0        - 46.836769 * t1 - 0.0001831 * t2 + 0.00200340 * t3 - 0.000000576 * t4 - 0.0000000434 * t5;

	double sec2deg = 1.0 / (60.0*60.0);
	zeta_A  *= sec2deg;
	z_A     *= sec2deg;
	theta_A *= sec2deg;
	eps_A   *= sec2deg;

	return  Rx3deg(-sec2deg * eps0) * Rzxz3deg( 90-zeta_A, theta_A, -90-z_A) * Rx3deg(eps_A) * r_ec;
}
