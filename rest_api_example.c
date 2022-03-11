rest_api_example()
{
	web_set_sockets_option("SSL_VERSION", "AUTO");
	

	lr_start_transaction("rest_get_example");
	
	web_rest("GET: url simple example",
		"URL=https://reqres.in/api/users?page=2",
		"Method=GET",
		"Snapshot=12345.inf",
		LAST);
	
	lr_end_transaction("rest_get_example", LR_AUTO);
	
	
	
	lr_start_transaction("rest_get_multiple_example");
	
	web_rest("GET: url filter example",
		"URL=https://reqres.in/api/users?page=2&page=3&page=4&page=5",
		"Method=GET",
		"Snapshot=123456.inf",
		LAST);

	lr_start_transaction("rest_get_multiple_example");
	
	
	
	lr_start_transaction("rest_get_headers_example");
	
	web_rest("GET: url get header example",
		"URL=https://reqres.in/api/users?page=25",
		"Method=GET",
		"Snapshot=123456.inf",
		HEADERS,
		"Name=authorization", "Value=token", ENDHEADER,
		"Name=key1", "Value=value1", ENDHEADER,
		"Name=key2", "Value={variable}", ENDHEADER,
		LAST);

	lr_start_transaction("rest_get_headers_example");
	
	
	
	lr_start_transaction("rest_get_response_save_example");
	
	web_reg_save_param_json(
		"ParamName=response_save_key",
		"QueryString=$.key_name",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);
	
	web_rest("GET: url response save example",
		"URL=https://reqres.in/api/users?page=2",
		"Method=GET",
		"Snapshot=12345.inf",
		LAST);
	
	lr_end_transaction("rest_get_response_save_example", LR_AUTO);
	
	
	
	lr_start_transaction("rest_post_json_example");
	
	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );
	
	web_rest("POST: post headers example",
		"URL=https://reqres.in/api/users",
		"Method=POST",
		"EncType=raw",
		"Snapshot=1234567.inf",
		"Body={\r\n"
		"\"name\": \"post\",\r\n"
		"\"job\": \"student\"\r\n"
		"}",
		HEADERS,
		"Name=Content-Type", "Value=application/json", ENDHEADER,
		LAST);
	
	lr_end_transaction("rest_post_json_example", LR_AUTO);
	
	
	
	lr_start_transaction("rest_post_form_and_header_example");
	
	web_rest("POST: post form and header example ",
		"URL=https://reqres.in/api/users",
		"Method=POST",
		"EncType=multipart/form-data",
		"Snapshot=t1234567.inf",
		ITEMDATA,
		"Name=name", "Value=postForm", ENDITEM,
		"Name=job", "Value=student", ENDITEM,
		HEADERS,
		"Name=authorization", "Value=token", ENDHEADER,
		LAST);
	
	lr_end_transaction("rest_post_form_and_header_example", LR_AUTO);
			
			
	
	lr_start_transaction("rest_post_response_save_example");
	
	web_reg_save_param_json(
		"ParamName=response_save_login_token",
		"QueryString=$.token",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);
	
	web_rest("POST: post response save example",
		"URL=https://reqres.in/api/login",
		"Method=POST",
		"EncType=raw",
		"Snapshot=t123456.inf",
		"Body={\r\n"
		"\"email\": \"eve.holt@reqres.in\",\r\n"
		"\"password\": \"cityslicka\"\r\n"
		"}",
		HEADERS,
		"Name=Content-Type", "Value=application/json", ENDHEADER,
		LAST);
	
	lr_end_transaction("rest_post_response_save_example", LR_AUTO);
	
	
	
	lr_start_transaction("rest_put_example");
	
	web_rest("PUT: https://reqres.in/api/users",
		"URL=https://reqres.in/api/users",
		"Method=PUT",
		"EncType=raw",
		"Snapshot=t108419.inf",
		"Body={\r\n"
		"\"name\": \"put\",\r\n"
		"\"job\": \"student\"\r\n"
		"}",
		HEADERS,
		"Name=Content-Type", "Value=application/json", ENDHEADER,
		LAST);
	
	
	lr_end_transaction("rest_put_example", LR_AUTO);
	
	
	
}
