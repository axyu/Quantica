#include <string.h>

#include "test.h"
#include "quid.h"
#include "engine.h"
#include "bootstrap.h"

#define BS_MAGIC "__zero()__"

static void bootstrap_zero(){
    struct btree btree;
    const char fname[] = "test_bootstrap";
	struct quid quid;

	const char squid[] = "{00000000-0000-0000-0000-000000000000}";
	strtoquid(squid, &quid);
	btree_init(&btree, fname);
	bootstrap(&btree);

	size_t len;
	void *data = btree_get(&btree, &quid, &len);
	ASSERT(data);
	ASSERT(!strncmp(data, BS_MAGIC, len));

	btree_close(&btree);
	btree_purge(fname);
}

static void bootstrap_init(){
	struct btree btree;
	const char fname[] = "test_bootstrap2";
	struct quid quid;

	const char squid[] = "{00000000-00c1-a150-ab68-01cafaa7a081}";
	const char data[] = "{\"pre\":\"_init\",\"description\":\"bootstrap\"}";
	strtoquid(squid, &quid);
	btree_init(&btree, fname);
	bootstrap(&btree);

	size_t len;
	void *rdata = btree_get(&btree, &quid, &len);
	ASSERT(rdata);
	ASSERT(!strncmp(rdata, data, len));

	btree_close(&btree);
	btree_purge(fname);
}

TEST_IMPL(bootstrap) {
	/* Run testcase */
	bootstrap_zero();
	bootstrap_init();

	RETURN_OK();
}