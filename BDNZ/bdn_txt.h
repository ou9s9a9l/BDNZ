#include <avr/pgmspace.h>
const unsigned char PROGMEM  s[260][30] =  {"",
	"下行一道发车信号开放",
	"下行2道发车信号开放",
	"下行3道发车信号开放",
	"下行4道发车信号开放",
	"下行5道发车信号开放",
	"下行6道发车信号开放",
	"下行7道发车信号开放",
	"下行8道发车信号开放",
	"下行9道发车信号开放",
	"下行十道发车信号开放",
	"下行十一道发车信号开放",
	"下行十2道发车信号开放",
	"下行十3道发车信号开放",
	"下行十4道发车信号开放",
	"下行十5道发车信号开放",
	"下行十6道发车信号开放",
	"下行十7道发车信号开放",
	"下行十8道发车信号开放",
	"下行十9道发车信号开放",
	"下行2十道发车信号开放",
	"下行一道接车信号开放",
	"下行2道接车信号开放",
	"下行3道接车信号开放",
	"下行4道接车信号开放",
	"下行5道接车信号开放",
	"下行6道接车信号开放",
	"下行7道接车信号开放",
	"下行8道接车信号开放",
	"下行9道接车信号开放",
	"下行十道接车信号开放",
	"下行十一道接车信号开放",
	"下行十2道接车信号开放",
	"下行十3道接车信号开放",
	"下行十4道接车信号开放",
	"下行十5道接车信号开放",
	"下行十6道接车信号开放",
	"下行十7道接车信号开放",
	"下行十8道接车信号开放",
	"下行十9道接车信号开放",
	"下行2十道接车信号开放",
	"下行一道通过信号开放",
	"下行2道通过信号开放",
	"下行3道通过信号开放",
	"下行4道通过信号开放",
	"下行5道通过信号开放",
	"下行6道通过信号开放",
	"下行7道通过信号开放",
	"下行8道通过信号开放",
	"下行9道通过信号开放",
	"下行十道通过信号开放",
	"下行十一道通过信号开放",
	"下行十2道通过信号开放",
	"下行十3道通过信号开放",
	"下行十4道通过信号开放",
	"下行十5道通过信号开放",
	"下行十6道通过信号开放",
	"下行十7道通过信号开放",
	"下行十8道通过信号开放",
	"下行十9道通过信号开放",
	"下行2十道通过信号开放",
	"进一道停车",
	"进2道停车",
	"进3道停车",
	"进4道停车",
	"进5道停车",
	"进6道停车",
	"进7道停车",
	"进8道停车",
	"进9道停车",
	"进十道停车",
	"进十一道停车",
	"进十2道停车",
	"进十3道停车",
	"进十4道停车",
	"进十5道停车",
	"进十6道停车",
	"进十7道停车",
	"进十8道停车",
	"进十9道停车",
	"进2十道停车",
	"经一道通过",
	"经2道通过",
	"经3道通过",
	"经4道通过",
	"经5道通过",
	"经6道通过",
	"经7道通过",
	"经8道通过",
	"经9道通过",
	"经十道通过",
	"经十一道通过",
	"经十2道通过",
	"经十3道通过",
	"经十4道通过",
	"经十5道通过",
	"经十6道通过",
	"经十7道通过",
	"经十8道通过",
	"经十9道通过",
	"经2十道通过",
	"上行一道发车信号开放",
	"上行2道发车信号开放",
	"上行3道发车信号开放",
	"上行4道发车信号开放",
	"上行5道发车信号开放",
	"上行6道发车信号开放",
	"上行7道发车信号开放",
	"上行8道发车信号开放",
	"上行9道发车信号开放",
	"上行十道发车信号开放",
	"上行十一道发车信号开放",
	"上行十2道发车信号开放",
	"上行十3道发车信号开放",
	"上行十4道发车信号开放",
	"上行十5道发车信号开放",
	"上行十6道发车信号开放",
	"上行十7道发车信号开放",
	"上行十8道发车信号开放",
	"上行十9道发车信号开放",
	"上行2十道发车信号开放",
	"上行一道接车信号开放",
	"上行2道接车信号开放",
	"上行3道接车信号开放",
	"上行4道接车信号开放",
	"上行5道接车信号开放",
	"上行6道接车信号开放",
	"上行7道接车信号开放",
	"上行8道接车信号开放",
	"上行9道接车信号开放",
	"上行十道接车信号开放",
	"上行十一道接车信号开放",
	"上行十2道接车信号开放",
	"上行十3道接车信号开放",
	"上行十4道接车信号开放",
	"上行十5道接车信号开放",
	"上行十6道接车信号开放",
	"上行十7道接车信号开放",
	"上行十8道接车信号开放",
	"上行十9道接车信号开放",
	"上行2十道接车信号开放",
	"上行一道通过信号开放",
	"上行2道通过信号开放",
	"上行3道通过信号开放",
	"上行4道通过信号开放",
	"上行5道通过信号开放",
	"上行6道通过信号开放",
	"上行7道通过信号开放",
	"上行8道通过信号开放",
	"上行9道通过信号开放",
	"上行十道通过信号开放",
	"上行十一道通过信号开放",
	"上行十2道通过信号开放",
	"上行十3道通过信号开放",
	"上行十4道通过信号开放",
	"上行十5道通过信号开放",
	"上行十6道通过信号开放",
	"上行十7道通过信号开放",
	"上行十8道通过信号开放",
	"上行十9道通过信号开放",
	"上行2十道通过信号开放",
	"进一道停车",
	"进2道停车",
	"进3道停车",
	"进4道停车",
	"进5道停车",
	"进6道停车",
	"进7道停车",
	"进8道停车",
	"进9道停车",
	"进十道停车",
	"进十一道停车",
	"进十2道停车",
	"进十3道停车",
	"进十4道停车",
	"进十5道停车",
	"进十6道停车",
	"进十7道停车",
	"进十8道停车",
	"进十9道停车",
	"进2十道停车",
	"经一道通过",
	"经2道通过",
	"经3道通过",
	"经4道通过",
	"经5道通过",
	"经6道通过",
	"经7道通过",
	"经8道通过",
	"经9道通过",
	"经十道通过",
	"经十一道通过",
	"经十2道通过",
	"经十3道通过",
	"经十4道通过",
	"经十5道通过",
	"经十6道通过",
	"经十7道通过",
	"经十8道通过",
	"经十9道通过",
	"经2十道通过",
	"下行列车一接近",
	"下行列车2接近",
	"下行列车3接近",
	"下行列车进站",
	"下行列车一离去",
	"下行列车2离去",
	"下行列车3离去",
	"下行列车接近",
	"下行列车离去",
	"空",
	"上行列车一接近",
	"上行列车2接近",
	"上行列车3接近",
	"上行列车进站",
	"上行列车一离去",
	"上行列车2离去",
	"上行列车3离去",
	"上行列车接近",
	"上行列车离去",
	"空",
	"信息中断",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"空",
	"麻田镇",
	"麻田镇",
};