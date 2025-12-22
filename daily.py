import requests
import os

NOTION_NAME = os.environ.get('NOTION_NAME')
NOTION_TOKEN = os.environ.get('NOTION_TOKEN')
SCORE_DB_ID = os.environ.get('SCORE_DB_ID')

headers = {
    "Authorization": f"Bearer {NOTION_TOKEN}",
    "Content-Type": "application/json",
    "Notion-Version": "2022-06-28"
}

def apply_penalty():
    print(f"📉 {NOTION_NAME}님의 데일리 스택 차감 시작...")

    # 1. 내 행(Row) 찾기
    query_url = f"https://api.notion.com/v1/databases/{SCORE_DB_ID}/query"
    payload = {
        "filter": {
            "property": "이름",
            "title": {"equals": NOTION_NAME}
        }
    }
    res = requests.post(query_url, json=payload, headers=headers)
    data = res.json()

    if not data['results']:
        print("❌ 현황판 데이터를 찾을 수 없습니다.")
        return

    page_id = data['results'][0]['id']
    current_stack = data['results'][0]['properties']['스택']['number'] or 0

    # 2. 스택 -1 차감
    new_stack = current_stack - 1

    # (선택사항) 만약 스택이 너무 낮으면 경고 메시지 출력 가능
    if new_stack < 0:
        print("🚨 경고: 스택이 마이너스입니다! 벌금 위기!")

    # 3. 업데이트
    update_url = f"https://api.notion.com/v1/pages/{page_id}"
    update_data = { "properties": { "스택": { "number": new_stack } } }

    requests.patch(update_url, json=update_data, headers=headers)
    print(f"✅ 오늘 하루가 지나 스택이 차감되었습니다. ({current_stack} -> {new_stack})")

if __name__ == "__main__":
    apply_penalty()