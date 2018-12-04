#pragma once

#include <vector>

namespace CreateCoin{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "seed-east.CreateCoinit.com:2001",          // CreateCoinit
   "seed-central.CreateCoinit.com:2001",       // CreateCoinit
   "seed-west.CreateCoinit.com:2001",          // CreateCoinit
   "CreateCoin-seed1.abit-more.com:2001",      // abit
   "52.74.152.79:2001",                   // smooth.witness
   "seed.CreateCoind.com:34191",               // roadscape
   "anyx.co:2001",                        // anyx
   "seed.xeldal.com:12150",               // xeldal
   "seed.CreateCoinnodes.com:2001",            // wackou
   "seed.liondani.com:2016",              // liondani
   "gtg.CreateCoin.house:2001",                // gtg
   "seed.jesta.us:2001",                  // jesta
   "CreateCoind.pharesim.me:2001",             // pharesim
   "5.9.18.213:2001",                     // pfunk
   "lafonaCreateCoin.com:2001",                // lafona
   "seed.rossco99.com:2001",              // rossco99
   "CreateCoin-seed.altcap.io:40696",          // ihashfury
   "seed.roelandp.nl:2001",               // roelandp
   "CreateCoin.global:2001",                   // klye
   "seed.eCreateCoin.ws:2001",                 // good-karma
   "seed.timcliff.com:2001",              // timcliff
   "104.199.118.92:2001",                 // clayop
   "seed.CreateCoinviz.com:2001",              // ausbitbank
   "CreateCoin-seed.lukestokes.info:2001",     // lukestokes
   "seed.CreateCoinian.info:2001",             // drakos
   "seed.followbtcnews.com:2001",         // followbtcnews
   "node.mahdiyari.info:2001",            // mahdiyari
   "seed.curieCreateCoin.com:2001",            // curie
   "seed.riverCreateCoin.com:2001",            // riverhead
   "148.251.237.104:2001",                // CreateCoin-bounty
   "seed1.blockbrothers.io:2001",         // blockbrothers
   "CreateCoinseed-fin.privex.io:2001",        // privex
   "seed.jamzed.pl:2001",                 // jamzed
   "seed1.cryptobot.news:2001",           // libertyranger
   "seed.thecryptodrive.com:2001",        // thecryptodrive
   "seed.brandonfrye.us:2001",            // brandonfrye
   "seed.firepower.ltd:2001"              // firepower
};
#endif

} } } // CreateCoin::plugins::p2p
