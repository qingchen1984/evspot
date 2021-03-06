#pragma once
#ifndef __EVSIP_NET_STACK_H__
#define __EVSIP_NET_STACK_H__


struct evspot_stack_s {
  /* magic */
  uint32_t magic;

  /* Raw */
  uint8_t *raw;
  size_t raw_len;
  uint8_t *payload;
  size_t payload_len;

  /* Ethernet */
  const struct ethhdr *eth;

  /* VLAN */

  /* ICMP */
  const struct icmphdr *icmp;

  /* ARP */
  const struct arphdr *arp;

  /* IPv4 */
  const struct iphdr *ipv4;

  /* TCP */
  const struct tcphdr *tcp;

  /* UDP */
  const struct udphdr *udp;
};

uint8_t evspot_stack_eth(struct evspot_stack_s *pCtx);

uint8_t evspot_stack_vlan(struct evspot_stack_s *pCtx);

uint8_t evspot_stack_ipv4(struct evspot_stack_s *pCtx);

uint8_t evspot_stack_tcp(struct evspot_stack_s *pCtx);

uint8_t evspot_stack_udp(struct evspot_stack_s *pCtx);

uint8_t evspot_stack_icmp(struct evspot_stack_s *pCtx);

uint8_t evspot_stack_arp(struct evspot_stack_s *pCtx);

uint8_t evspot_stack_init(evspot_stack_t **ppCtx);

uint8_t evspot_stack_parse(evspot_stack_t *pCtx, uint8_t *raw, size_t raw_len);

uint8_t evspot_stack_free(evspot_stack_t *pCtx);

#endif /* __EVSIP_NET_STACK_H__ */
// vim: ts=2:sw=2:expandtab
