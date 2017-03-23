//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   18时:02分:33秒  
// ><文件     ><  cf-parser.c  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\libobs\util  
// ><隶属工程><   obs-studio  
// ><当前用户 ><  Administrator  
// ><作者     ><  Open Broadcaster Software   
// ><出处     >< 《 https://obsproject.com/ 》  
// ><目的     >< 【】  
// ><设计技术 ><   
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
// ><         ><  4.  
//////////////////////////////////迭代修改///////////////////////////////////////////////////////  
// ><作者     ><  xzm  
// ><修改日期 ><  2017年:03月:21日   18时:02分:33秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Copyright (c) 2013 Hugh Bailey <obs.jim@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "cf-parser.h"

void cf_adderror(struct cf_parser *p, const char *error, int level,
		const char *val1, const char *val2, const char *val3)
{
	uint32_t row, col;
	lexer_getstroffset(&p->cur_token->lex->base_lexer,
			p->cur_token->unmerged_str.array,
			&row, &col);

	if (!val1 && !val2 && !val3) {
		error_data_add(&p->error_list, p->cur_token->lex->file,
				row, col, error, level);
	} else {
		struct dstr formatted;
		dstr_init(&formatted);
		dstr_safe_printf(&formatted, error, val1, val2, val3, NULL);

		error_data_add(&p->error_list, p->cur_token->lex->file,
				row, col, formatted.array, level);

		dstr_free(&formatted);
	}
}

bool cf_pass_pair(struct cf_parser *p, char in, char out)
{
	if (p->cur_token->type != CFTOKEN_OTHER ||
	    *p->cur_token->str.array != in)
		return p->cur_token->type != CFTOKEN_NONE;

	p->cur_token++;

	while (p->cur_token->type != CFTOKEN_NONE) {
		if (*p->cur_token->str.array == in) {
			if (!cf_pass_pair(p, in, out))
				break;
			continue;

		} else if(*p->cur_token->str.array == out) {
			p->cur_token++;
			return true;
		}

		p->cur_token++;
	}

	return false;
}
