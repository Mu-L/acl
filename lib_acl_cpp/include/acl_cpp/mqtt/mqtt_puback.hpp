#pragma once

#include "mqtt_message.hpp"

namespace acl {

class mqtt_puback : public mqtt_message {
public:
	mqtt_puback(mqtt_type_t type = MQTT_PUBACK);
	virtual ~mqtt_puback(void);

	void set_pkt_id(unsigned short id);

	unsigned short get_pkt_id(void) const {
		return pkt_id_;
	}

	bool to_string(string& out);

	int update(const char* data, int dlen);

public:
	int update_header_var(const char* data, int dlen);
	int update_topic_qos(const char* data, int dlen);

private:
	bool finished_;
	char hbuf_[2];
	unsigned hlen_;

	unsigned short pkt_id_;
};

} // namespace acl
